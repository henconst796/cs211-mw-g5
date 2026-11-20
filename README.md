CS211 Group Project: 2048 and Luhn Checksum
Session / group: MW, Group 5
Repository: https://github.com/henconst796/cs211-mw-g5

Group members
| Name | GitHub username |

| Vincent Nguyen | vinnyn5647-a11y |
| Quang Truong | henconst796 |
| Touthy Mienphilom | kmienphilom-jpg |

What is in this project
| Path | What it is |

| game2048/ | The 2048 game: main.cpp, 2048_helper.h / 2048_helper.cpp (movement, board, game helpers), save_load.h / save_load.cpp (saving and loading), and sample_save.txt (a valid example save) |
| luhn/ | The Luhn checksum checker: main.cpp, luhn.h, luhn.cpp |
| tests/move_tests.cpp | Automatic tests for the four move functions (no random tiles) |
| tests.md | Every test we ran, with expected and actual results |
| report.pdf | Design explanation, dry runs, Luhn flowchart and function diagram |
| contributions.md | Who did what, every pull request, and outside help used |

Program summaries
2048. A 5 x 5 version of the sliding-tile game. Every move slides all tiles in one direction, and two equal tiles that meet merge into one tile worth their sum. A merged tile cannot merge again in the same move. The new tile's value is added to the score. After every move that changes the board, exactly one new 2 appears in a random empty cell; a move that changes nothing adds no tile and is not counted. The game shows the score, the number of moves and the highest tile, announces a win when a tile reaches 2048 (you can keep playing), and ends when the board is full and no merge is possible. The game can be saved to and loaded from a text file.

Luhn checksum. Reads 16-digit numbers one line at a time and reports whether each one is correctly formatted and whether it passes the Luhn checksum (the check digit test used for card numbers). Wrong formats (wrong length, letters, spaces, symbols) are reported separately from numbers that are formatted correctly but fail the checksum. Passing the checksum does not mean a real card exists.

## How to build

You need g++ with C++17. We used MinGW-w64 g++ from MSYS2 on Windows. Open a terminal in the **top-level project folder** (the one that contains `game2048`, `luhn` and `tests`) and run:

    g++ -std=c++17 -Wall -Wextra -pedantic game2048/main.cpp game2048/2048_helper.cpp game2048/save_load.cpp -o game2048_app
    g++ -std=c++17 -Wall -Wextra -pedantic luhn/main.cpp luhn/luhn.cpp -o luhn_app
    g++ -std=c++17 -Wall -Wextra -pedantic tests/move_tests.cpp game2048/2048_helper.cpp -o move_tests

All three build with no warnings. Each program has its own `main` and builds separately. No absolute paths are needed.

Note: the VS Code "Run Code" button compiles only one file, so it cannot build these programs. Use the commands above.

## How to run

| Program | Windows (PowerShell) | macOS / Linux |
|---|---|---|
| 2048 | `.\game2048_app` | `./game2048_app` |
| Luhn | `.\luhn_app` | `./luhn_app` |
| Move tests | `.\move_tests` | `./move_tests` |

`move_tests` should print `15 of 15 tests passed`.

## 2048 controls

Type one lowercase letter and press Enter. The same list is shown at startup and when you press `h`.

| Key | What it does |
|---|---|
| `u` `d` `l` `r` | Move up, down, left, right |
| `s` | Save the game to `savegame.txt` (replaces any earlier save) |
| `o` | Open (load) the game from `savegame.txt` |
| `n` | Start a new game. It asks `(y/n)` first; only `y` starts over |
| `h` | Show the help list |
| `e` | Exit |

- Anything else, including uppercase letters, whole words or an empty line, prints "Invalid command" and changes nothing.
- A new game clears the board, sets the score and moves to 0, and places two 2s in different random cells.
- When no move is possible (the board is full and no two neighbors are equal), the game says "Game over". Moves are refused, but `s`, `o`, `n`, `h` and `e` still work.
- If input ends (Ctrl+Z then Enter on Windows, Ctrl+D on macOS/Linux), the program prints "No more input. Goodbye!" and stops.

## Save file behavior

- There is one save slot: `savegame.txt` in the **current working directory**, which is the folder your terminal is in when you start the program. If you follow the commands above, that is the top-level project folder.
- Pressing `s` again replaces the earlier save.
- Pressing `o` checks the whole file before using it. If the file is missing, the first line is not `CS211_2048_V1`, the score or move count is missing, negative or not a whole number, there are not exactly 25 board numbers, a board number is not 0 or a power of two (2, 4, 8, ...), or there is anything after the board, the program says what is wrong and **the current game is not changed**.
- To try the provided example, copy it to the top-level folder, start the game and press `o`. On Windows: `copy game2048\sample_save.txt savegame.txt`. It loads with score 8 and 3 moves.

The save file has 7 lines: the marker, then the score and move count, then the 5 rows of the board. This is `game2048/sample_save.txt`:

    CS211_2048_V1
    8 3
    4 4 0 0 0
    0 0 0 0 0
    2 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0

    ## Luhn usage

Type a 16-digit number and press Enter. Type `Q` or `q` to quit (end of input also quits).

| You type | Result |
|---|---|
| `4532015112830366` | Correct format. Checksum PASSES. |
| `4532015112830367` | Correct format. Checksum FAILS. |
| `453201511283036` (15 digits) | Invalid format |
| `4532 015112830366` (space inside) | Invalid format |

## Tests

All tests and their results are in `tests.md`: the Luhn tests, 15 automatic movement tests, and in-game tests for scoring, save/load (including broken save files) and the game loop.

## Known limitations

- The board is always 5 x 5, and there is only one save slot.
- Commands must be lowercase single letters; `L` or `left` count as invalid.
- Random tiles come from `rand()` seeded with the clock once per run, so two games started in the same second begin the same way.
- A save file is checked for format, not for whether the board could happen in a real game. For example, a board full of 1024s loads as long as every number is 0 or a power of two.
- Numbers in a save file too large to fit in an `int` (about 2.1 billion) are rejected as invalid, so the load fails and the game is unchanged.
- The Luhn checker accepts exactly 16 digits with nothing else on the line, so numbers written with spaces or dashes are rejected.
- Both programs run in the terminal only; there is no graphical interface.