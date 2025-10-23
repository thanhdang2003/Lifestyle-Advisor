#include <iostream>
#include <string>

/**
 * @brief Greets the user and introduces the quiz.
 */
void greetUser();

/**
 * @brief Asks a question with four options and returns a score.
 * @param question The question text.
 * @param a Option 1.
 * @param b Option 2.
 * @param c Option 3.
 * @param d Option 4.
 * @return An integer score (1–4).
 */
int askQuestion(const std::string& question,
                const std::string& a,
                const std::string& b,
                const std::string& c,
                const std::string& d);

/**
 * @brief Prints personalized advice for each question.
 * @param q1 Eating habits answer.
 * @param q2 Exercise frequency answer.
 * @param q3 Sleep hours answer.
 * @param q4 Stress level answer.
 * @param q5 Water intake answer.
 * @param totalScore Total score from all answers.
 */
void givePersonalizedAdvice(int q1, int q2, int q3, int q4, int q5, int totalScore);

/**
 * @brief Provides overall evaluation based on total score.
 * @param score The total score.
 * @return A string with overall health advice.
 */
std::string getOverallAdvice(int score);

/**
 * @brief Asks whether the user wants to restart the quiz.
 * @return True if user chooses to restart, false otherwise.
 */
bool askRestart();

/**
 * @brief Runs one full round of the quiz.
 */
void runQuiz();

int main() {
    bool again = true;
    while (again) {
        runQuiz(); // Run one quiz session
        again = askRestart(); // Ask if the user wants to restart
    }

    std::cout << "\nThank you for using the Fitness Advisor! Stay healthy!\n";
    return 0;
}

void greetUser() {
    std::cout << "=============================" << std::endl;
    std::cout << "    LIFESTYLE ADVISOR QUIZ  " << std::endl;
    std::cout << "=============================" << std::endl;
    std::cout << "Answer 5 questions to get personalized advice." << std::endl;
    std::cout << "Choose 1, 2, 3, or 4 for each question.\n\n";
}

void runQuiz() {
    greetUser();
    int q1, q2, q3, q4, q5;

    // Ask five lifestyle questions
    q1 = askQuestion("A. How would you describe your eating habits?",
                     "Lots of fast food and soda",
                     "Sometimes unhealthy",
                     "Fairly balanced diet",
                     "Healthy and mostly home-cooked");

    q2 = askQuestion("B. How often do you exercise each week?",
                     "Never",
                     "1-2 times",
                     "3-4 times",
                     "5 or more times");

    q3 = askQuestion("C. How many hours do you sleep on average?",
                     "Less than 5 hours",
                     "Around 6 hours",
                     "About 7 hours",
                     "8 or more hours");

    q4 = askQuestion("D. How stressed do you feel daily?",
                     "Very stressed",
                     "Quite stressed",
                     "Sometimes stressed",
                     "Relaxed and balanced");

    q5 = askQuestion("E. How many glasses of water do you drink per day?",
                     "Less than 3",
                     "4-5",
                     "6-8",
                     "More than 8");

    // Calculate total lifestyle score
    int totalScore = q1 + q2 + q3 + q4 + q5;

    // Display personalized and overall feedback
    givePersonalizedAdvice(q1, q2, q3, q4, q5, totalScore);
}

int askQuestion(const std::string& question,
                const std::string& a,
                const std::string& b,
                const std::string& c,
                const std::string& d) {
    int choice;
    int score = 0;
    do {
        // Display the question and possible answers
        std::cout << question << std::endl;
        std::cout << "1. " << a << std::endl;
        std::cout << "2. " << b << std::endl;
        std::cout << "3. " << c << std::endl;
        std::cout << "4. " << d << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        // Assign a score based on the user’s answer
        switch (choice) {
            case 1:
                score = 1;
                break;
            case 2:
                score = 2;
                break;
            case 3:
                score = 3;
                break;
            case 4:
                score = 4;
                break;
            default:
                std::cout << "Invalid input. Please choose 1–4." << std::endl;
                continue;
        }
        break;
    } while (true);

    return score;
}

void givePersonalizedAdvice(int q1, int q2, int q3, int q4, int q5, int totalScore) {
    std::cout << "\n--- Personalized Tips ---" << std::endl;

    // Eating habits
    switch (q1) {
        case 1:
            std::cout << "Try cutting down on junk food gradually." << std::endl;
            break;
        case 2:
            std::cout << "You are improving, but aim for more whole foods." << std::endl;
            break;
        case 3:
            std::cout << "Nice balance! Keep monitoring your nutrition." << std::endl;
            break;
        case 4:
            std::cout << "Excellent diet! Continue eating clean." << std::endl;
            break;
    }

    // Exercise
    switch (q2) {
        case 1:
            std::cout << "Start with light activities like walking daily. " << std::endl;
            break;
        case 2:
            std::cout << "Good start! Try to add one more workout day." << std::endl;
            break;
        case 3:
            std::cout << "Solid routine! Maintain consistency." << std::endl;
            break;
        case 4:
            std::cout << "Impressive! Make sure to rest properly too." << std::endl;
            break;
    }

    // Sleep
    switch (q3) {
        case 1:
            std::cout << "Sleep deprivation harms your focus—prioritize rest." << std::endl;
            break;
        case 2:
            std::cout << "Try sleeping 1 more hour per night for better energy." << std::endl;
            break;
        case 3:
            std::cout << "Good sleep schedule. Keep it steady." << std::endl;
            break;
        case 4:
            std::cout << "Excellent! Continue maintaining 8 hours of rest." << std::endl;
            break;
    }

    // Stress
    switch (q4) {
        case 1:
            std::cout << "Consider meditation or journaling to manage stress." << std::endl;
            break;
        case 2:
            std::cout << "Try short breaks or light stretching to relax." << std::endl;
            break;
        case 3:
            std::cout << "You are managing stress decently, keep balancing it." << std::endl;
            break;
        case 4:
            std::cout << "Good mental balance! Keep a positive mindset." << std::endl;
            break;
    }

    // Water intake
    switch (q5) {
        case 1:
            std::cout << "You are likely dehydrated. Aim for at least 6 glasses a day." << std::endl;
            break;
        case 2:
            std::cout << "Better than average! Try keeping a water bottle near you." << std::endl;
            break;
        case 3:
            std::cout << "Nice hydration habit! Maintain your water routine." << std::endl;
            break;
        case 4:
            std::cout << "Excellent hydration! Keep it up and stay refreshed." << std::endl;
            break;
    }
    // Show overall lifestyle evaluation
    std::cout << "\n--- Overall Evaluation ---" << std::endl;
    std::cout << getOverallAdvice(totalScore) << std::endl;
}

std::string getOverallAdvice(int score) {
    switch (score) { // Show advice based on score
        case 5:
        case 6:
        case 7:
        case 8:
            return "You need a lifestyle reset. Start small and build healthy habits.";
        case 9:
        case 10:
        case 11:
        case 12:
            return "You are doing okay, but there’s room for improvement.";
        case 13:
        case 14:
        case 15:
        case 16:
            return "Good job! Keep your balance and consistency.";
        case 17:
        case 18:
        case 19:
        case 20:
            return "Excellent! You are maintaining a very healthy lifestyle.";
        default:
            return "Error calculating result.";
    }
}

bool askRestart() {
    char ans;
    std::cout << "\nWould you like to try again? (y/n): ";
    std::cin >> ans;
    return (ans == 'y' || ans == 'Y');
}
