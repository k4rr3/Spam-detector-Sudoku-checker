# Spam-detector-Sudoku-checker
This is our second project developed in C++ where we created a basic spam detector and a sudoku checker.

SPAM DETECTOR
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
This program reads a .txt file where there are some keywords (known as spam words) and a text. If the spam words are in the text, the program is able to detect
them. Then the program decides if the text is spam with the detections of the spam words, and if the spam words are detected two or more times in the text and the 
total percentage of spam words is higher than 50% then the text is considered as spam. The number of repetitions and the percentage of spam is shown when the 
program is executed.

SUDOKU CHECKER --> credits to @didicayu
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
This program reads a sudoku of a .txt and automatically formats it. Then the sudoku is checked and if there's an error, it reports where the error is. When an error is detected, the program ends and says that the sudoku is incorrect.

NOTE: The makefile can be used to try all the sample texts in the jp folder. So you can do: make clean && make all && make test
