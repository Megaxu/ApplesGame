#include "Leaderboard.h"
#include "Game.h"

namespace ApplesGame {

	std::vector<std::string> NAMES{ "Boss", "BigBoss", "Killer123", "Molodec", "Halk", "Leader", "Zombie", "Max", "Min", "Unknown" };

	void InitResult(Result& result, std::string name, int score) {
		result.name = name;
		result.score = score;
	}

	void InitLeaderboard(Leaderboard& leaderboard, Game& game) {

		size_t size = NAMES.size();

		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT; ++i) {
			InitResult(leaderboard.results[i], GetRandomName(size - i - 1), 6 - i);
		}
	}

	void UpdateLeaderboard(Leaderboard& leaderboard, Game& game) {
		SortLeaderboard(leaderboard, game, LEADERBOARD_PLAYERS_COUNT);
		SearchAndReplace(leaderboard, game, LEADERBOARD_PLAYERS_COUNT);
		game.isLeaderboardOpen = true;
	}

	void SortLeaderboard(Leaderboard& leaderboard, Game& game, int size) {
		for (int i = 0; i < size - 1; ++i) {
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

		// Идея в том, что если кто-то с таким же количеством очков, но полученными ранее, то он выше в плане места
		if (!CheckPlayer(leaderboard, game, size)) {
			for (int i = size; i >= 0; --i) {
				if (leaderboard.results[i].score < game.playerResult.score) {
					leaderboard.results[i].score = game.playerResult.score;
					leaderboard.results[i].name = game.playerResult.name;
					game.playerPlace = i;
					break;
				}
			}
		}
		else {
			if (leaderboard.results[game.playerPlace].score < game.playerResult.score) {
				leaderboard.results[game.playerPlace].score = game.playerResult.score;

				SortLeaderboard(leaderboard, game, LEADERBOARD_PLAYERS_COUNT);

			}
		}
	}

	std::string GetRandomName(int size) {
		int randomIndex = rand() % size;
		std::string temp = NAMES[size];
		NAMES[size] = NAMES[randomIndex];
		NAMES[randomIndex] = temp;

		return NAMES[size];
	}

	bool CheckPlayer(Leaderboard& leaderboard, Game& game, int size) {
		for (int i = 0; i < size; ++i) {
			if (leaderboard.results[i].name == "Player") {
				game.playerPlace = i;

				return true;
			}
		}

		return false;
	}
}