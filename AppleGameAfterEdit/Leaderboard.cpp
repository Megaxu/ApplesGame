#include "Leaderboard.h"
#include "Game.h"

namespace ApplesGame {
	
	std::vector<std::string> NAMES { "Boss", "BigBoss", "Killer123", "Molodec", "Halk", "Leader", "Zombie", "Max", "Min", "Unknown" };

	void InitResult(Result& result, std::string name, int score) {
		result.name = name;
		result.score = score;
	}

	void InitLeaderboard(Leaderboard& leaderboard, Game& game) {
		
		size_t size = NAMES.size();

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			InitResult(leaderboard.results[i], SetRandomName(size - i - 1), rand() % 10 + 1);

		}
	}

	void UpdateLeaderboard(Leaderboard& leaderboard, Game& game) {
		SortLeaderBoard(leaderboard, LEADERBOARD_PLAYERS_COUNT);
		SearchAndReplace(leaderboard, game, LEADERBOARD_PLAYERS_COUNT);
		game.isLeaderboardOpen = true;
	}

	void SortLeaderBoard(Leaderboard& leaderboard, int size) {

		for (int i = 0; i < size; i++) {
			if (leaderboard.results[i].score < leaderboard.results[i + 1].score) {
				int tempScore = leaderboard.results[i].score;
				std::string tempName = leaderboard.results[i].name;
				leaderboard.results[i].score = leaderboard.results[i + 1].score;
				leaderboard.results[i].name = leaderboard.results[i + 1].name;
				leaderboard.results[i + 1].score = tempScore;
				leaderboard.results[i + 1].name = tempName;
			}
		}
	}

	void SearchAndReplace(Leaderboard& leaderboard, Game& game, int size) {
		if (!CheckPlayer(leaderboard, game)) {
			for (int i = size; i >= 0; i--) {
				if (leaderboard.results[i].score < game.playerResult.score) {
					leaderboard.results[i].score = game.playerResult.score;
					leaderboard.results[i].name = game.playerResult.name;
					game.playerPlace = i;
				}
			}
		}
		else {
			if (leaderboard.results[game.playerPlace].score < game.playerResult.score) {
				leaderboard.results[game.playerPlace].score = game.playerResult.score;
			}
		}
	}

	std::string SetRandomName(int end) {
		int randomIndex = rand() % end;
		std::string temp = NAMES[end];
		NAMES[end] = NAMES[randomIndex];
		NAMES[randomIndex] = temp;
		
		return NAMES[end];
	}

	bool CheckPlayer(Leaderboard& leaderboard, const Game& game) {
		for (Result result : leaderboard.results) {
			if (result.name == game.playerResult.name) {
				return true;
			}
		}

		return false;
	}
}
