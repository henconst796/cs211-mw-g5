# Luhn Tests (Part B)

| # | Test input or action | Expected result | Actual result | Pass/Fail |
|---|---|---|---|---|
| 1 | 4532015112830366 | Correct format; checksum passes | Correct format. Checksum PASSES. | Pass |
| 2 | 4532015112830367 | Correct format; checksum fails | Correct format. Checksum FAILS. | Pass |
| 3 | 0000000000000018 | Correct format; leading zeros preserved; passes | Correct format. Checksum PASSES. | Pass |
| 4 | 453201511283036 | Reject: 15 digits | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 5 | 45320151128303666 | Reject: 17 digits | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 6 | 453201511283036X | Reject: non-digit | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 7 | 4532 015112830366 (internal space) | Reject: malformed input | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 8 | Several checks followed by exit (Q) | Results correct; loop exits cleanly | Each number gave the correct result; typing Q printed "Goodbye!" and the program ended. | Pass |
| 9 | Ctrl+Z then Enter (end of input) | Program exits cleanly | Printed "Goodbye!" and the program ended. | Pass |

## 2048 Movement Tests (PR 2)

Built and run from the main project folder (no warnings):

```
g++ -std=c++17 -Wall -Wextra -pedantic tests/move_tests.cpp game2048/2048_helper.cpp -o move_tests
.\move_tests
```

These tests call the move functions directly, so **no random tile is added**. This keeps the movement result separate from the random insertion, as the handout asks. Left/right tests use row 0 of an otherwise empty board; up/down tests use column 0 (values listed top to bottom).

| # | What it checks | Start | Move | Expected result | Expected score / changed | Actual result | Actual score / changed | Pass/Fail |
|---|---|---|---|---|---|---|---|---|
| 1 | Slides through gaps | 0 2 0 2 0 (row 0) | left | 4 0 0 0 0 | +4, changed: yes | 4 0 0 0 0 | +4, changed: yes | Pass |
| 2 | Three equal tiles (no double merge) | 2 2 2 0 0 (row 0) | left | 4 2 0 0 0 | +4, changed: yes | 4 2 0 0 0 | +4, changed: yes | Pass |
| 3 | Five equal tiles | 2 2 2 2 2 (row 0) | left | 4 4 2 0 0 | +8, changed: yes | 4 4 2 0 0 | +8, changed: yes | Pass |
| 4 | New 4 must not merge again | 2 2 4 0 0 (row 0) | left | 4 4 0 0 0 | +4, changed: yes | 4 4 0 0 0 | +4, changed: yes | Pass |
| 5 | Two merges in one move (score) | 4 4 8 8 0 (row 0) | left | 8 16 0 0 0 | +24, changed: yes | 8 16 0 0 0 | +24, changed: yes | Pass |
| 6 | Nothing can move (unchanged) | 2 4 8 0 0 (row 0) | left | 2 4 8 0 0 | +0, changed: no | 2 4 8 0 0 | +0, changed: no | Pass |
| 7 | Four equal tiles | 2 2 2 2 0 (row 0) | left | 4 4 0 0 0 | +8, changed: yes | 4 4 0 0 0 | +8, changed: yes | Pass |
| 8 | Slide with no merge (no score) | 0 0 2 0 4 (row 0) | left | 2 4 0 0 0 | +0, changed: yes | 2 4 0 0 0 | +0, changed: yes | Pass |
| 9 | Right merges the rightmost pair | 2 2 2 0 0 (row 0) | right | 0 0 0 2 4 | +4, changed: yes | 0 0 0 2 4 | +4, changed: yes | Pass |
| 10 | Right through gaps | 4 0 4 0 4 (row 0) | right | 0 0 0 4 8 | +8, changed: yes | 0 0 0 4 8 | +8, changed: yes | Pass |
| 11 | Reaching 2048 | 1024 1024 0 0 0 (row 0) | right | 0 0 0 0 2048 | +2048, changed: yes | 0 0 0 0 2048 | +2048, changed: yes | Pass |
| 12 | Up through gaps | 0 2 0 2 0 (column 0, top to bottom) | up | 4 0 0 0 0 | +4, changed: yes | 4 0 0 0 0 | +4, changed: yes | Pass |
| 13 | Up: no double merge | 2 2 4 0 0 (column 0, top to bottom) | up | 4 4 0 0 0 | +4, changed: yes | 4 4 0 0 0 | +4, changed: yes | Pass |
| 14 | Down merges the bottom pair | 2 2 2 0 0 (column 0, top to bottom) | down | 0 0 0 2 4 | +4, changed: yes | 0 0 0 2 4 | +4, changed: yes | Pass |
| 15 | Down: already at the bottom (unchanged) | 0 0 0 0 2 (column 0, top to bottom) | down | 0 0 0 0 2 | +0, changed: no | 0 0 0 0 2 | +0, changed: no | Pass |

Result: **15 of 15 passed.**

### In the game (game2048/main.cpp, starting board)

| # | Action | Expected | Actual | Pass/Fail |
|---|---|---|---|---|
| 16 | Press `l` on the starting board | Rows become 4 2 4 0 0 / 0 0 0 0 0 / 4 2 0 0 0 / 2 0 0 0 0 / 4 4 2 0 0 before the random tile; score goes from 0 to 12 (4 + 8); exactly one new tile appears | Score: 12; the rows matched; exactly one new tile appeared | Pass |
| 17 | Press `x` (invalid command) | No new tile, score unchanged | No new tile; score unchanged | Pass |


## 2048 Save and Load Tests (Save/Load PR)

Built and run from the main project folder (no warnings):

```
g++ -std=c++17 -Wall -Wextra -pedantic game2048/main.cpp game2048/2048_helper.cpp game2048/save_load.cpp -o game
.\game
```

For tests 20-25, `savegame.txt` was replaced with the text shown (rows separated by ` / `). Then `l` was pressed on the starting board (Score 12, Moves 1) before `o`, to show that a failed load leaves the current game unchanged.

| # | Action | Expected | Actual | Pass/Fail |
|---|---|---|---|---|
| 18 | Press `l`, `s` (save), `r`, then `o` (load) | After `s`: "Game saved". After `r`: score and moves go up. After `o`: the exact saved board, Score 12 and Moves 1 come back; no new tile | `savegame.txt` held CS211_2048_V1 / 12 1 / the 5 rows on screen. After `r`, score and moves went up. After `o`: "Game loaded", Score 12, Moves 1, every cell matched the saved rows | Pass |
| 19 | Teacher's sample file: CS211_2048_V1 / 8 3 / 4 4 0 0 0 / 0 0 0 0 0 / 2 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0; press `o` at the start | "Game loaded"; Score 8, Moves 3; board matches the file; no new tile | "Game loaded from savegame.txt."; Score 8, Moves 3; board matched; no new tile | Pass |
| 20 | Invalid tile: first board row is 3 4 0 0 0 | Load failed; game unchanged | "Load failed: board values must be 0 or a power of two"; still Score 12, Moves 1, same board | Pass |
| 21 | Incomplete: only 4 board rows (20 numbers) | Load failed; game unchanged | "Load failed: the board needs exactly 25 whole numbers"; still Score 12, Moves 1, same board | Pass |
| 22 | Wrong marker: first line is CS211_2048_V2 | Load failed; game unchanged | "Load failed: the first line must be CS211_2048_V1"; still Score 12, Moves 1, same board | Pass |
| 23 | Extra content: the word `hello` after the board | Load failed; game unchanged | "Load failed: there is extra content after the board"; still Score 12, Moves 1, same board | Pass |
| 24 | Negative score: second line is -8 3 | Load failed; game unchanged | "Load failed: the score and move count can't be negative"; still Score 12, Moves 1, same board | Pass |
| 25 | Missing file: `savegame.txt` deleted | Load failed; game unchanged | "Load failed: savegame.txt was not found"; still Score 12, Moves 1, same board | Pass |

Result: **8 of 8 passed.**

## 2048 Game Loop Tests (Game Loop PR)

Built and run from the main project folder (no warnings):

    g++ -std=c++17 -Wall -Wextra -pedantic game2048/main.cpp game2048/2048_helper.cpp game2048/save_load.cpp -o game
    .\game

Note: tests 16-25 were run before this PR, when the game always started from the fixed starter board. The game now starts with two random 2s, so this PR sets up exact boards by loading a `savegame.txt` (shown with rows separated by ` / `) and pressing `o`. The movement and save/load code did not change.

| # | Action | Expected | Actual | Pass/Fail |
|---|---|---|---|---|
| 26 | Start the program | Help is shown; board has exactly two 2s in different cells; Score 0, Moves 0, Highest tile 2 | Help shown; two 2s in different cells; Score: 0, Moves: 0, Highest tile: 2 | Pass |
| 27 | Press `h` | Command list is shown; board, score and moves unchanged | Command list shown; nothing else changed | Pass |
| 28 | Type `x`, then a whole word, then `y` at the Choice prompt | "Invalid command" each time; nothing changes | "Invalid command. Type one letter, or h for help." all three times; nothing changed | Pass |
| 29 | Press `n`, then answer `n` | Game is not reset | "New game cancelled."; board, score and moves unchanged | Pass |
| 30 | Press `n`, then answer `y` | New game: two 2s, Score 0, Moves 0 | New board with two 2s; Score: 0, Moves: 0, Highest tile: 2 | Pass |
| 31 | Press `e` | Program ends | "Goodbye!" and the program ended | Pass |
| 32 | Press Ctrl+Z then Enter (end of input) | Program ends cleanly, no endless loop | "No more input. Goodbye!" and the program ended | Pass |
| 33 | Slide with no merge: load CS211_2048_V1 / 0 0 / 0 0 2 0 4 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0, press `l` | Row 0 becomes 2 4 0 0 0 before the random tile; exactly one new 2; Score stays 0; Moves 0 to 1 | Row 0 was 2 4 0 0 0; one new 2 appeared; Score: 0, Moves: 1 | Pass || # | Action | Expected | Actual | Pass/Fail |
|---|---|---|---|---|
| 34 | Unchanged move: load CS211_2048_V1 / 0 0 / 2 4 8 0 0 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0, press `l` | No new tile; Score and Moves unchanged | "Nothing moved, so no new tile was added."; Score: 0, Moves: 0 | Pass |
| 35 | Full board with a possible merge: load CS211_2048_V1 / 10 4 / 2 2 4 8 16 / 4 8 16 32 64 / 2 4 8 16 32 / 4 8 16 32 64 / 2 4 8 16 32, press `l` | Move is allowed; row 0 becomes 4 4 8 16 0, then the new 2 fills the only empty cell; Score 10 to 14; Moves 4 to 5 | Row 0 was 4 4 8 16 2; Score: 14, Moves: 5 | Pass |
| 36 | Full board, no moves: load CS211_2048_V1 / 10 4 / 2 4 2 4 2 / 4 2 4 2 4 / 2 4 2 4 2 / 4 2 4 2 4 / 2 4 2 4 2, then press `l`, `h`, `e` | "Game over" after loading; movement refused; help and exit still work | "Game over! No moves are left..."; `l` gave "Game over: no moves are possible..."; help shown; "Goodbye!" | Pass |
| 37 | Reaching 2048: load CS211_2048_V1 / 100 7 / 1024 1024 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0 / 0 0 0 0 0, press `r`, then `l` | Row 0 becomes 0 0 0 0 2048 before the random tile; win message; Score 100 to 2148; Moves 7 to 8; play continues | "You made a 2048 tile. You win! You can keep playing."; Score: 2148, Moves: 8; after `l`, Moves: 9 | Pass |

Result: **12 of 12 passed.**

## Final clean-extraction build test (Final docs PR)

| # | Action | Expected | Actual | Pass/Fail | 
|---|---|---|---|---|
| 38 | Downloaded the docs/final-package branch as a ZIP, extracted it into a new empty folder, opened a terminal in the top-level folder and ran the three build commands from README.md. Then ran move_tests, started the game, checked 4532015112830366 in the Luhn program, and loaded the sample save (copy game2048\sample_save.txt savegame.txt, then o) | All three build with no warnings; move_tests prints 15 of 15 tests passed; the game starts with two 2s and Score 0, Moves 0; Luhn reports "Correct format. Checksum PASSES."; the sample save loads with Score 8, Moves 3 | All three built with no warnings; 15 of 15 tests passed; the game started with two 2s and Score 0, Moves 0; Luhn printed "Correct format. Checksum PASSES."; the sample save loaded with Score 8, Moves 3 | Pass |
