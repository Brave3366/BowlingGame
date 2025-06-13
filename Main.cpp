#include <iostream>
#include <vector>

using namespace std;

// Class representing a single frame
class Frame {
public:
    int firstRoll;
    int secondRoll;
    int thirdRoll;  // Only for 10th frame
    bool isTenthFrame;

    Frame(int roll1, int roll2, bool isTenth = false, int roll3 = 0) {
        isTenthFrame = isTenth;

        // Validations for Input
        if (roll1 < 0 || roll1 > 10 || roll2 < 0 || roll2 > 10 || roll3 < 0 || roll3 > 10)
            throw invalid_argument("Each roll must be between 0 and 10 pins.");

        if (!isTenth && (roll1 + roll2 > 10)) {
            throw invalid_argument("Sum of two rolls cannot exceed 10 in a normal frame.");
        }

        firstRoll = roll1;
        secondRoll = roll2;
        thirdRoll = isTenth ? roll3 : 0;
    }

    // Check if frame is a strike
    bool isStrike() const {
        return firstRoll == 10;
    }

    // Check if frame is a spare
    bool isSpare() const {
        return !isStrike() && (firstRoll + secondRoll == 10);
    }

    // Return total score of pins in the frame
    int getScore() const {
        return firstRoll + secondRoll + thirdRoll;
    }
};

// Class representing bowling game
class BowlingGame {
private:
    vector<Frame> frames;

public:
    // Add a frame to the game
    void addFrame(int r1, int r2, int r3 = 0) {
        bool isTenth = (frames.size() == 9);

        if (frames.size() >= 10)
            throw runtime_error("Game already has 10 frames.");

        Frame frame(r1, r2, isTenth, r3);
        frames.push_back(frame);
    }

    // Calculate total score with strike/spare bonuses
    int calculateScore() {
        int score = 0;

        for (size_t i = 0; i < frames.size(); ++i) {
            Frame& curr = frames[i];
            score += curr.getScore();

            if (i < 9) {  // Bonus only applies for first 9 frames
                if (curr.isStrike()) {
                    score += strikeBonus(i);
                } else if (curr.isSpare()) {
                    score += spareBonus(i);
                }
            }
        }

        return score;
    }

private:
    // Bonus after a strike = next 2 rolls
    int strikeBonus(size_t i) {
        if (i + 1 >= frames.size()) return 0;

        Frame& next = frames[i + 1];
        if (next.isStrike() && i + 2 < frames.size()) {
            return next.firstRoll + frames[i + 2].firstRoll;
        } else {
            return next.firstRoll + next.secondRoll;
        }
    }

    // Bonus after a spare = next 1 roll
    int spareBonus(size_t i) {
        if (i + 1 >= frames.size()) return 0;
        return frames[i + 1].firstRoll;
    }
};

int main() {
    BowlingGame game;
    cout << "\nWelcome to the Bowling Game!! \n";

    int i = 1;
    while (i <= 10) {
        int r1 = 0, r2 = 0, r3 = 0;
        cout << "\nFrame " << i << ":\n";

        try {
            cout << "Enter score for Roll 1: ";
            cin >> r1;

            if (r1 == 10 && i != 10) {
                r2 = 0;
            } else {
                cout << "Enter score for Roll 2: ";
                cin >> r2;
            }

            if (i == 10 && (r1 == 10 || r1 + r2 == 10)) {
                cout << "Bonus! Enter score for Roll 3: ";
                cin >> r3;
            }

            game.addFrame(r1, r2, r3);
            ++i; // increment if frame is added successfully

        } catch (const exception& e) {
            cerr << "Invalid input: " << e.what() << " Please re-enter scores for the frame " << i << ".\n";
        }
    }

    // To display final score
    int total = game.calculateScore();
    cout << "\nGame Over!"<<endl<<"Your Final Score is: " << total << endl;

    return 0;
}
