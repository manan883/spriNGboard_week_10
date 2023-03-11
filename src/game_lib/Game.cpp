#include "Game.h"

#include <iostream>
#include <sstream>

using namespace std;

Game::Game ()
  : places{},
    purses{},
    currentPlayer(0)
{
  for (int i = 0; i < 50; i++)
  {
    {
      ostringstream oss(ostringstream::out);
      oss << "Pop Question " << i;
      popQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Science Question " << i;
      scienceQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Sports Question " << i;
      sportsQuestions.push_back(oss.str());
    }

    {
      ostringstream oss(ostringstream::out);
      oss << "Rock Question " << i;
      rockQuestions.push_back(oss.str());
    }
  }
}

bool Game::add (string playerName)
{
  players.push_back(playerName);
  places[players.size()] = 0;
  purses[players.size()] = 0;
  inPenaltyBox[players.size()] = false;

  cout << playerName << " was added" << endl;
  cout << "They are player number " << players.size() << endl;
  return true;
}

void Game::roll (int roll)
{
  cout << players[currentPlayer] << " is the current player" << endl;
  cout << "They have rolled a " << roll << endl;

  if (inPenaltyBox[currentPlayer])
  {
    if (roll % 2 != 0)
    {
      isGettingOutOfPenaltyBox = true;

      cout << players[currentPlayer] << " is getting out of the penalty box" << endl;
      places[currentPlayer] = places[currentPlayer] + roll;
      if (places[currentPlayer] > 11) places[currentPlayer] = places[currentPlayer] - 12;

      cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << endl;
      cout << "The category is " << currentCategory() << endl;
      askQuestion();
    }
    else
    {
      cout << players[currentPlayer] << " is not getting out of the penalty box" << endl;
      isGettingOutOfPenaltyBox = false;
    }
  }
  else
  {
    places[currentPlayer] = places[currentPlayer] + roll;
    if (places[currentPlayer] > 11) {
      places[currentPlayer] = places[currentPlayer] - 12;
    }

    cout << players[currentPlayer] << "'s new location is " << places[currentPlayer] << endl;
    cout << "The category is " << currentCategory() << endl;
    askQuestion();
  }
}

void Game::askQuestion ()
{
  if (currentCategory() == "Pop")
  {
    cout << popQuestions.front() << endl;
    popQuestions.pop_front();
  }
  else if (currentCategory() == "Science")
  {
    cout << scienceQuestions.front() << endl;
    scienceQuestions.pop_front();
  }
  else if (currentCategory() == "Sports")
  {
    cout << sportsQuestions.front() << endl;
    sportsQuestions.pop_front();
  }
  else if (currentCategory() == "Rock")
  {
    cout << rockQuestions.front() << endl;
    rockQuestions.pop_front();
  }
}

string Game::currentCategory ()
{
  vector<string> categories = {
    "Pop", "Science", "Sports", "Rock"
  };
  return categories[places[currentPlayer] % 4];
}

bool Game::wasCorrectlyAnswered ()
{
  if (inPenaltyBox[currentPlayer])
  {
    if (isGettingOutOfPenaltyBox)
    {
      cout << "Answer was correct!!!!" << endl;
      purses[currentPlayer]++;
      cout << players[currentPlayer]
           << " now has "
           << purses[currentPlayer]
        <<  " Gold Coins." << endl;

      bool winner = didPlayerWin();
      currentPlayer++;
      if (currentPlayer == players.size()) currentPlayer = 0;

      return winner;
    }
    else
    {
      currentPlayer++;
      if (currentPlayer == players.size()) currentPlayer = 0;
      return true;
    }
  }
  else
  {
    cout << "Answer was corrent!!!!" << endl;
    purses[currentPlayer]++;
    cout << players[currentPlayer]
         << " now has "
         << purses[currentPlayer]
         << " Gold Coins."
         << endl;

    bool winner = didPlayerWin();
    currentPlayer++;
    if (currentPlayer == players.size()) {
      currentPlayer = 0;
    }

    return winner;
  }
}

bool Game::wrongAnswer ()
{
  cout << "Question was incorrectly answered" << endl;
  cout << players[currentPlayer] + " was sent to the penalty box" << endl;
  inPenaltyBox[currentPlayer] = true;

  currentPlayer++;
  if (currentPlayer == players.size()) {
    currentPlayer = 0;
  }
  return true;
}

bool Game::didPlayerWin ()
{
  return purses[currentPlayer] != 6;
}

