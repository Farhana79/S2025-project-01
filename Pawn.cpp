/**
 * @Name: Farhana Sultana
 * @date: 02/14/2025
 * @file Pawn.cpp
 * @brief This file contains the implementation of the Pawn class, representing a chess pawn piece.
 *
 * The Pawn class is derived from the ChessPiece class and implements pawn-specific functionality such as movement,
 * promotion, and the ability to double-jump.
 *
 */


#include "Pawn.hpp"


/**
 * @brief Default Constructor. All boolean values are default initialized to false.
 * @note Remember to construct the base-class as well!
 */
Pawn::Pawn() : ChessPiece(), double_jumpable_(false) {
    // Base class (ChessPiece) is constructed by default constructor.
}

/**
* @brief Parameterized constructor.
* @param : A const reference to the color of the Pawn (a string).
*     Set the color "BLACK" if the provided string contains non-alphabetic characters (eg. numbers or symbols).
*     If the string is purely alphabetic, it is converted and stored in uppercase.
*     NOTE: We do not supply a default value for color, the first parameter.
*           Notice that if we do, we override the default constructor.
* @param : The 0-indexed row position of the Pawn (as a const reference to an integer).
*          Default value -1 if not provided, or if the value provided is outside the
*          board's dimensions, [0, BOARD_LENGTH)
* @param : The 0-indexed column position of the Pawn (as a const reference to an integer).
*          Default value -1 if not provided, or if the value provided is outside the
*          board's dimensions, [0, BOARD_LENGTH)
* @param : A flag indicating whether the Pawn is moving up on the board, or not (as a const reference to a boolean).
*          Default value false if not provided.
* @param : A flag indicating whether the Pawn can double jump two spaces forward or not (as a const reference to a boolean).
*          Default value false if not provided.
* @post : The private members are set to the values of the corresponding parameters.
*   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
*   If EITHER of the provided row or col are out-of-bounds,
*      that is between 0 (inclusive) and BOARD_LENGTH (not inclusive),
*      then BOTH are set to -1 (regardless of being in-bounds or not).
* @note Remember to construct the base-class as well using these parameters!
*/
Pawn::Pawn(const std::string &color, int row, int column, bool movingUp, bool doubleJumpable)
        : ChessPiece(color, row, column, movingUp), double_jumpable_(doubleJumpable) {
    // Base class (ChessPiece) is constructed using the provided parameters
}

/**
 * @brief Gets the value of the flag for the Pawn can double jump
 * @return The boolean value stored in double_jumpable_
 */
bool Pawn::canDoubleJump() const {
    // Simply returns the value of double_jumpable_ flag
    return double_jumpable_;
}

/**
 * @brief Toggles the double_jumpable_ flag of the Pawn
 * @post Sets the double_jumpable_ flag to opposite its current value
 */
void Pawn::toggleDoubleJump() {
    // Toggle the value of double_jumpable_
    double_jumpable_ = !double_jumpable_;
}


/**
 * @brief Determines if this pawn can be promoted to another piece
 *     A pawn can be promoted if its row has reached the farthest row it can move up (or down) to.
 *     This is determined by the board size and the Piece's movingUp_ member.
 *
 * EXAMPLE: If a pawn is movingUp and the board has 8 rows,
 *           then it can promoted only if it is in the 7th row (0-indexed)
 * @return True if this pawn can be promoted. False otherwise.
 */
bool Pawn::canPromote() const {
    // Determine if pawn is in the last row (7th row) for "movingUp" or the first row (0th row) for "movingDown"
    return (isMovingUp()  && getRow() == ChessPiece::BOARD_LENGTH -1) || (!isMovingUp() && getRow() == 0);
}
