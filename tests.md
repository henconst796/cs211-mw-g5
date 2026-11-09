
| # | Test input or action | Expected result | Actual result | Pass/Fail |
|---|---|---|---|---|
| 1 | 4532015112830366 | Correct format; checksum passes | Correct format. Checksum PASSES. | Pass |
| 2 | 4532015112830367 | Correct format; checksum fails | Correct format. Checksum FAILS. | Pass |
| 3 | 0000000000000018 | Correct format; leading zeros preserved; passes | Correct format. Checksum PASSES. | Pass |
| 4 | 453201511283036 | Reject: 15 digits | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 5 | 45320151128303666 | Reject: 17 digits | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 6 | 453201511283036X | Reject: non-digit | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 7 | 4532 015112830366 (internal space) | Reject: malformed input | Invalid format: please enter exactly 16 digits (0-9), with no spaces, letters, or symbols. | Pass |
| 8 | Several checks followed by exit (Q) | Results correct; loop exits cleanly | Each number, correct result; typing Q printed "Goodbye!" and the program ended. | Pass |
| 9 | Ctrl+Z then Enter (end of input) | Program exits cleanly | Printed "Goodbye!" and the program ended. | Pass |