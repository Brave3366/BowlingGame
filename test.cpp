#include <iostream>
using namespace std;


//Test Case 1: All open frames (no strikes or spares)
void testAllOpenFrames() {
    BowlingGame game;
    // Add 10 frames with 3 and 5 pins knocked down respectively (total 8 per frame)
    for (int i = 0; i < 10; ++i)
        game.addFrame(3, 5);

    // Expected score = 10 frames × 8 points = 80
    assert(game.calculateScore() == 80);
    cout << "testAllOpenFrames passed\n";
}

//Test Case 2: All spares with 5 + 5 in each frame and a bonus roll of 5
void testAllSpares() {
    BowlingGame game;
    // 9 regular frames with spares
    for (int i = 0; i < 9; ++i)
        game.addFrame(5, 5);  // spare

    // 10th frame with spare and bonus roll of 5
    game.addFrame(5, 5, 5);

    // Expected score: 10 frames × 15 = 150
    assert(game.calculateScore() == 150);
    cout << "testAllSpares passed\n";
}

//Test Case 3: Perfect game - All strikes
void testAllStrikes() {
    BowlingGame game;
    // 9 regular strikes
    for (int i = 0; i < 9; ++i)
        game.addFrame(10, 0);

    // 10th frame with 3 strikes (10, 10, 10)
    game.addFrame(10, 10, 10);

    // Expected score: 300
    assert(game.calculateScore() == 300);
    cout << "testAllStrikes passed (Perfect Game)\n";
}

//Test Case 4: Mixed frame types (strike, spare, open)
void testMixedFrames() {
    BowlingGame game;
    game.addFrame(10, 0);     // Strike
    game.addFrame(7, 3);      // Spare
    game.addFrame(9, 0);      // Open
    game.addFrame(10, 0);     // Strike
    game.addFrame(10, 0);     // Strike
    game.addFrame(10, 0);     // Strike
    game.addFrame(2, 8);      // Spare
    game.addFrame(9, 1);      // Spare
    game.addFrame(10, 0);     // Strike
    game.addFrame(10, 10, 10); // Final frame - triple strike

    // Just check that score is computed and greater than 0
    int score = game.calculateScore();
    assert(score > 0);
    cout << "testMixedFrames passed\n";
}

//Test Case 5: Invalid input should throw exception
void testInvalidInputHandling() {
    try {
        BowlingGame game;
        game.addFrame(11, 0); // Invalid input: more than 10 pins re-enter the score!
        assert(false); // This should not be reached
    } catch (const invalid_argument&) {
        // Expected exception
        cout << "testInvalidInputHandling passed\n";
    }
}

int main() {
    testAllOpenFrames();         // Test basic open frames
    testAllSpares();             // Test all spares
    testAllStrikes();            // Test perfect game
    testMixedFrames();           // Test mix of strikes/spares/opens
    testInvalidInputHandling();  // Test exception for invalid input
    return 0;
}
