/**
* @Name: Farhana Sultana
* @Date: 02/14/2025
* This file defines the ChessPiece class representing a generic chess piece.
* The class provides functionality to store and manage the color, row, column,
* and movement direction of the chess piece. It includes methods for constructing
* a chess piece with both default and parameterized values, validating attributes,
* and displaying the piece's information.
**/
#include <iostream>
#include "ChessPiece.hpp"

/**
     * @brief Default Constructor : All values
     * Default-initializes all private members.
     * Booleans are default-initialized to False.
     * Default color : "BLACK"
     * Default row & columns: -1 (ie. represents that it has not been put on the board yet)
     * */
ChessPiece::ChessPiece() {
    color_ = "BLACK";
    row_ = -1;
    column_ = -1;
    movingUp_ = false;
}

/**
        * @brief Parameterized constructor.
        * @param : A const reference to the color of the Chess Piece (a string).
        *     Set the color "BLACK" if the provided string contains ANY non-alphabetic characters.
        *     If the string is purely alphabetical, it is converted and stored in uppercase
        *     NOTE: We DO NOT supply a default value for color, the first parameter.
        *           Notice that if we do, we override the default constructor.
        * @param : The 0-indexed row position of the Chess Piece (as a const reference to an integer).
        *          Default value -1 if not provided.
        * @param : The 0-indexed column position of the Chess Piece (as a const reference to an integer).
        *          Default value -1.
        * @param : A flag indicating whether the Chess Piece is moving up on the board
        *          or not (as a const reference to a boolean). Default value False if not provided.
        * @post : The private members are set to the values of the corresponding parameters.
        *   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
        *   If EITHER of the provided row or col are out-of-bounds, where the bounds are between 0 (inclusive)
        *      and BOARD_LENGTH (not inclusive), then BOTH are set to -1 (regardless of being in-bounds or not).
    */
ChessPiece::ChessPiece(const std::string color, int row, int column, bool movingUp) {
    // Validate and set the color
    bool isAlphabetic = true;
    for (char c : color) {
        if (!std::isalpha(c)) {
            isAlphabetic = false;
            break;
        }
    }

    if (isAlphabetic) {
        // Convert the color to uppercase if it's purely alphabetic
        color_ = color;
        for (char& c : color_) {
            c = std::toupper(c);
        }
    } else {
        // Set color to "BLACK" if it contains non-alphabetic characters
        color_ = "BLACK";
    }

    // Validate and set the row and column
    if (row >= 0 && row < BOARD_LENGTH && column >= 0 && column < BOARD_LENGTH) {
        row_ = row;
        column_ = column;
    } else {
        // Set both row and column to -1 if either is out of bounds
        row_ = -1;
        column_ = -1;
    }

    // Set the movingUp flag
    movingUp_ = movingUp;
}


/**
 * @brief Gets the color of the chess piece.
 * @return std::string - The value stored in color_
 */
const std::string &ChessPiece::getColor() const {
    return color_;
}

bool ChessPiece::setColor(const std::string &color) {
    // Check if the input color is purely alphabetic
    bool isAlphabetic = true;
    for (char c : color) {
        if (!std::isalpha(c)) {
            isAlphabetic = false;
            break;
        }
    }

    // If the color is valid, convert it to uppercase and update the member variable
    if (isAlphabetic) {
        color_ = color;
        for (char& c : color_) {
            c = std::toupper(c);
        }
        return true; // Color was successfully set
    }

    // If the color is invalid, do nothing and return false
    return false;
}

/**
 * @brief Gets the row position of the chess piece.
 * @return The integer value stored in row_
 */
int ChessPiece::getRow() const {
    return row_;
}

/**
 * @brief Sets the row position of the chess piece
 * @param row A const reference to an integer representing the new row of the piece
 *
 * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
 *    the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
void ChessPiece::setRow(int row) {
    // Validate and set the row and column
    if (row >= 0 && row < BOARD_LENGTH) {
        row_ = row;
    } else {
        // Set both row and column to -1 if either is out of bounds
        row_ = -1;
        column_ = -1;
    }
}

/**
 * @brief Gets the column position of the chess piece.
 * @return The integer value stored in column_
 */
int ChessPiece::getColumn() const {
    return column_;
}


/**
     * @brief Sets the column position of the chess piece
     * @param row A const reference to an integer representing the new column of the piece
     *
     * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
     *  the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
void ChessPiece::setColumn(int column) {
    // Validate and set the row and column
    if (column >= 0 && column < BOARD_LENGTH) {
        column_ = column;
    } else {
        // Set both row and column to -1 if either is out of bounds
        row_ = -1;
        column_ = -1;
    }
}

/**
 * @brief Gets the value of the flag for if a chess piece is moving up
 * @return The boolean value stored in movingUp_
 */

bool ChessPiece::isMovingUp() const {
    return movingUp_;
}

/**
* @brief Sets the movingUp flag of the chess piece
* @param flag A const reference to an boolean representing whether the piece is now moving up or not
*/
void ChessPiece::setMovingUp(bool movingUp) {
    movingUp_ = movingUp;
}

/**
 * @brief Displays the chess piece's information in the following format,
 *        if it is considered on the board (ie. its row and col are not -1):
 * <COLOR> piece at (row, col) is moving <UP / DOWN>\n
 *
 * Otherwise an alternative format is used:
 * <COLOR> piece is not on the board\n
 * @note "\n" just means endline in this case. Please use "std::endl," don't print out the text "\n".
 * Example output 1:
   BLACK piece at (2,4) is moving UP
   Example output 2:
   WHITE piece is not on the board
 */
void ChessPiece::display() {
    if (row_ != -1 && column_ != -1) {
        // Piece is on the board
        std::cout << color_ << " piece at (" << row_ << "," << column_ << ") is moving "
                  << (movingUp_ ? "UP" : "DOWN") << std::endl;
    } else {
        // Piece is not on the board
        std::cout << color_ << " piece is not on the board" << std::endl;
    }
}


