#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_guess(char guess, char secret_word[], char display_word[], int word_length) {
    int correct = 0;
    for (int i = 0; i < word_length; i++) {
        if (secret_word[i] == guess && display_word[i] == '_') {
            display_word[i] = guess;
            correct = 1;
        }
    }
    return correct;
}

int is_word_complete(char display_word[], int word_length) {
    for (int i = 0; i < word_length; i++) {
        if (display_word[i] == '_') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char secret_word[] = "MENTOR";
    int word_length = strlen(secret_word);
    char display_word[word_length + 1];
    for (int i = 0; i < word_length; i++) {
        display_word[i] = '_';
    }
    display_word[word_length] = '\0';

    int lives = 6;
    char guess;
    char wrong_guesses[26] = "";
    int wrong_count = 0;

    printf("\n===========================================\n");
    printf("      HANGMAN WORD GUESSING GAME \n");
    printf("===========================================\n");

    while (lives > 0) {
        printf("\n-------------------------------------------\n");
        printf("Word: %s\n", display_word);
        printf("Lives Left: %d\n", lives);
        printf("Wrong Guesses: %s\n", wrong_guesses);
        printf("-------------------------------------------\n");

        printf("Enter your guess (A-Z): ");
        scanf(" %c", &guess);
        guess = toupper(guess);

        int already_guessed = 0;
        for (int i = 0; i < word_length; i++) {
            if (display_word[i] == guess) {
                already_guessed = 1;
                break;
            }
        }
        for (int i = 0; i < wrong_count; i++) {
            if (wrong_guesses[i] == guess) {
                already_guessed = 1;
                break;
            }
        }

        if (already_guessed) {
            printf("⚠  You already guessed '%c'! Try another letter.\n", guess);
            continue;
        }

        int correct = check_guess(guess, secret_word, display_word, word_length);

        if (!correct) {
            lives--;
            wrong_guesses[wrong_count++] = guess;
            wrong_guesses[wrong_count] = '\0';
            printf(" Oops! '%c' is not in the word.\n", guess);
        } else {
            printf(" Great! '%c' is correct!\n", guess);
        }

        if (is_word_complete(display_word, word_length)) {
            printf("\n Congratulations!\n");
            printf("You guessed the word correctly: %s\n", secret_word);
            printf(" You won the game!\n");
            break;
        }
    }

    if (lives == 0) {
        printf("\n Game Over!\n");
        printf("You lost! The correct word was: %s\n", secret_word);
    }

    printf("\n===========================================\n");
    printf("      Thanks for Playing! \n");
    printf("       Created By: Rahul Parihar \n");
    printf("===========================================\n\n");

    return 0;
}
