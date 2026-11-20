# Contributions

MW session, Group 5. Repository: https://github.com/henconst796/cs211-mw-g5

Every member reviewed and tested work beyond their own part, and all members remain responsible for understanding the whole submission.

## Members

| Member | GitHub username | Main responsibilities | Reviews and merges |

| Vincent Nguyen | vinnyn5647-a11y | Luhn program (Part B); 2048 move scoring and board-changed detection, the `.h`/`.cpp` split and the automatic move tests | Reviewed PR #2 and PR #6; merged PR #4 and PR #5 |
| Quang Truong | henconst796 | Created the repository; reorganized the files into `game2048/` and removed extra files; save/load with file checks | Reviewed PR #1 and PR #5; merged PR #3 and PR #6 |
| Touthy Mienphilom | kmienphilom-jpg | First version of the four move functions; game loop (menu, new game, help, win, game over, end of input); final documentation and package | Reviewed PR #3 and PR #4; merged PR #1 and PR #2 |

## Pull requests

| PR | Title | Author | Reviewer | Merger | Checks performed |

| [#1](https://github.com/henconst796/cs211-mw-g5/pull/1) | Add Luhn checksum program (Part B) | vinnyn5647-a11y | henconst796 | kmienphilom-jpg | Built with `-Wall -Wextra -pedantic`, no warnings; Luhn tests 1-9 in `tests.md` |
| [#2](https://github.com/henconst796/cs211-mw-g5/pull/2) | Move 2048 files into game2048/ and remove extra files | henconst796 | vinnyn5647-a11y | kmienphilom-jpg | Reviewer compared the files before and after the move to make sure no code was lost and that the `.exe`, the handout PDF and the duplicate header were the only files removed |
| [#3](https://github.com/henconst796/cs211-mw-g5/pull/3) | Add scoring and board-changed detection to moves; split 2048_helper into .h and .cpp | vinnyn5647-a11y | kmienphilom-jpg | henconst796 | 15 of 15 automatic move tests passed (`tests/move_tests.cpp`); in-game tests 16-17 |
| [#4](https://github.com/henconst796/cs211-mw-g5/pull/4) | Add save and load (s/o) with file checks | henconst796 | kmienphilom-jpg | vinnyn5647-a11y | Save/load tests 18-25, including broken and missing save files. Reviewer downloaded the branch, built it, saved and reloaded a game, and confirmed that loading with no save file shows an error |
| [#5](https://github.com/henconst796/cs211-mw-g5/pull/5) | Add game loop: menu, new game, win and game over | kmienphilom-jpg | henconst796 | vinnyn5647-a11y | Game-loop tests 26-37. Reviewer built the branch with no warnings and tried help, an invalid command, cancelling a new game, and the game-over board from test 36 |
| [#6](https://github.com/henconst796/cs211-mw-g5/pull/6) | Add final documentation: README, report, contributions | kmienphilom-jpg | vinnyn5647-a11y | henconst796 | Reviewer downloaded the branch, built both programs by following the README, and checked the report's dry runs against the program output (test 38) |

## Work committed before the pull request process

Before the group switched to branches and reviews, three commits went directly to `main`: the initial commit and a starter-code update by henconst796 (Oct 23 and Nov 8), the first version of the four move functions by kmienphilom-jpg (Nov 4, which later became `game2048/2048_helper.h` in PR #2), and a README note by henconst796 (Nov 8). All work after that went through the pull requests above.

## tools

- **Tools:** Visual Studio Code, g++ (MinGW-w64 from MSYS2) on Windows, and the GitHub website.

**How adapted code was checked:** every program was built with `g++ -std=c++17 -Wall -Wextra -pedantic` with no warnings; we ran every test in `tests.md` and compared the actual output with the expected result; every pull request was built and tested by a different member before it was merged; and the dry runs in `report.pdf` were checked against the real program output.