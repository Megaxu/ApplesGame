#include "Leaderboard.h"
#include "Game.h"

namespace ApplesGame {
	
	void InitResult(Result& result, std::string name, int score) {
		result.name = name;
		result.score = score;
	}

	void InitLeaderboard(Leaderboard& leaderboard, Game& game) {
		for (int i = 0; i < LEADERBOARD_PLAYERS_COUNT - 1; ++i) {
			InitResult(leaderboard.results[i], NAMES[0], rand() % 20 + 10);
		}
		leaderboard.results[LEADERBOARD_PLAYERS_COUNT - 1] = game.playerResult;
	}

	void UpdateLeaderboard(Leaderboard& leaderboard, const Game& game) {
		SortLeaderBoard(leaderboard, LEADERBOARD_PLAYERS_COUNT);
		SearchAndReplace(leaderboard, game);	
	}

//	void SortLeaderBoard(Leaderboard& leaderboard, int start, int size) {
//;
//		int pivot = leaderboard.results[size / 2].score;
//		int left = start;
//		int right = size - 1;
//
//		while (leaderboard.results[left].score <= leaderboard.results[right].score) {
//			while (leaderboard.results[left].score < pivot) {
//				++left;
//			}
//			while (leaderboard.results[right].score > pivot) {
//				--right;
//			}
//			if (left <= right) {
//				int tempScore = leaderboard.results[left].score;
//				std::string tempName = leaderboard.results[left].name;
//				leaderboard.results[left].score = leaderboard.results[right].score;
//				leaderboard.results[left].name = leaderboard.results[right].name;
//				leaderboard.results[right].score = tempScore;
//				leaderboard.results[right].name = tempName;
//				++left;
//				--right;
//			}
//		}
//
//		SortLeaderBoard(leaderboard, 0, right + 1);
//		SortLeaderBoard(leaderboard, left, size - left);
//	}

	void SortLeaderBoard(Leaderboard& leaderboard, int size) {

		for (int i = 0; i < size; i++) {
			if (leaderboard.results[i].score > leaderboard.results[i + 1].score) {
				int tempScore = leaderboard.results[i].score;
				std::string tempName = leaderboard.results[i].name;
				leaderboard.results[i].score = leaderboard.results[i + 1].score;
				leaderboard.results[i].name = leaderboard.results[i + 1].name;
				leaderboard.results[i + 1].score = tempScore;
				leaderboard.results[i + 1].name = tempName;
			}
		}
	}

	void SearchAndReplace(Leaderboard& leaderboard, const Game& game) {

	}
}
