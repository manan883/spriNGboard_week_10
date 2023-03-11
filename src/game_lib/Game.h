#pragma once

#include <list>
#include <string>
#include <vector>

class Game
{
  public:
    Game();

    bool add(std::string playerName);

    void roll(int roll);

    bool handleCorrectAnswer();
    bool handleIncorrectAnswer();

  private:
    void askQuestion();
    std::string currentCategory();
    bool hasPlayerNotWon();

  private:
    std::vector<std::string> players;
    std::vector<int>         places;
    std::vector<int>         purses;
    std::vector<bool>        inPenaltyBox;

    std::list<std::string> popQuestions;
    std::list<std::string> scienceQuestions;
    std::list<std::string> sportsQuestions;
    std::list<std::string> rockQuestions;

    unsigned int currentPlayer;
    bool isGettingOutOfPenaltyBox;
};

