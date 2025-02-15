/**
 * @Name: Farhana Sultana
 * @Date: 02/14/2025
 * @file ChessPiece.hpp
 * @brief Header file for the ChessPiece class.
 * This file defines the `ChessPiece` class which represents a basic chess piece.
 * The class includes various member variables and functions to manage the position,
 * color, and movement behavior of the chess piece on a chessboard. The class offers
 * a default constructor, parameterized constructor, getter and setter methods,
 * and a display function to show the chess piece's status.
 * The ChessPiece class can be used as a base class for specific types of chess pieces,
 * providing fundamental properties and methods for manipulating them on a chessboard.
 *
 */

#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP


#include <string>

class ChessPiece {


private:
    std::string color_;
    int row_;
    int column_;
    bool movingUp_;

public:
    static const int BOARD_LENGTH = 8;
    /**
     * @brief Default Constructor : All values
     * Default-initializes all private members.
     * Booleans are default-initialized to False.
     * Default color : "BLACK"
     * Default row & columns: -1 (ie. represents that it has not been put on the board yet)
     * */
    ChessPiece();

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
    ChessPiece(const std::string color, int row, int column,bool movingUp);

    /**
     * @brief Gets the color of the chess piece.
     * @return std::string - The value stored in color_
     */
    const std::string &getColor() const;

    /**
     * @brief Sets the color of the chess piece.
     * @param color A const string reference, representing the color to set the piece to.
     *     If the string contains non-alphabetic characters, the value is not set (ie. nothing happens)
     *     If the string is alphabetic, then all characters are converted and stored in uppercase
     * @post The color_ member variable is updated to the parameter value in uppercase
     * @return True if the color was set. False otherwise.
     */
    bool setColor(const std::string &color);

    /**
     * @brief Gets the row position of the chess piece.
     * @return The integer value stored in row_
     */
    int getRow() const;

    /**
     * @brief Sets the row position of the chess piece
     * @param row A const reference to an integer representing the new row of the piece
     *
     * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
     *    the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
    void setRow(int row);

    /**
     * @brief Gets the column position of the chess piece.
     * @return The integer value stored in column_
     */
    int getColumn() const;


    /**
     * @brief Sets the column position of the chess piece
     * @param row A const reference to an integer representing the new column of the piece
     *
     * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
     *  the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
 */
    void setColumn(int column);

    /**
     * @brief Gets the value of the flag for if a chess piece is moving up
     * @return The boolean value stored in movingUp_
 */
    bool isMovingUp() const;

    /**
    * @brief Sets the movingUp flag of the chess piece
    * @param flag A const reference to an boolean representing whether the piece is now moving up or not
    */
    void setMovingUp(bool movingUp);

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
    void display();
};


#endif //CHESS_PIECE_HPP
