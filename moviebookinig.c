
#include <stdio.h>
#include <string.h>
#define MAX_MOVIES 5
#define MAX_BOOKINGS 10
typedef struct {
    char name[50];
    char time[10];
    int seats;
    int booked;
} Movie;
typedef struct {
    char movieName[50];
    char userName[50];
    int seatsBooked;
} Booking;
void displayMovies(Movie movies[]) {
    printf("Movie Menu:\n");
    for (int i = 0; i < MAX_MOVIES; i++) {
        printf("%d. %s (%s) - %d seats available\n", i + 1, movies[i].name, movies[i].time, movies[i].seats - movies[i].booked);
    }
}
void bookTicket(Movie movies[], Booking bookings[], int *bookingCount) {
    int movieChoice;
    printf("Enter the movie number you want to book: ");
    scanf("%d", &movieChoice);

    if (movieChoice < 1 || movieChoice > MAX_MOVIES) {
        printf("Invalid movie choice. Please try again.\n");
        return;
    }

    Movie *selectedMovie = &movies[movieChoice - 1];
    if (selectedMovie->seats - selectedMovie->booked <= 0) {
        printf("Sorry, no seats available for this movie.\n");
        return;
    }

    char userName[50];
    printf("Enter your name: ");
    scanf("%s", userName);

    int seatsBooked;
    printf("Enter the number of seats you want to book: ");
    scanf("%d", &seatsBooked);

    if (seatsBooked > selectedMovie->seats - selectedMovie->booked) {
        printf("Sorry, not enough seats available for this movie.\n");
        return;
    }
    selectedMovie->booked += seatsBooked;
    strcpy(bookings[*bookingCount].movieName, selectedMovie->name);
    bookings[*bookingCount].seatsBooked = seatsBooked;
    (*bookingCount)++;
    printf("Ticket booked successfully!\n");
}
void displayBookings(Booking bookings[], int bookingCount) {
    printf("Bookings:\n");
    for (int i = 0; i < bookingCount; i++) {
        printf("%d. %s - %s (%d seats)\n", i + 1, bookings[i].movieName, bookings[i].userName, bookings[i].seatsBooked);
    }
}
int main() {
    Movie movies[MAX_MOVIES] = {
        {"Movie 1", "10:00 AM", 100, 0},
        {"Movie 2", "1:00 PM", 150, 0},
        {"Movie 3", "4:00 PM", 120, 0},
        {"Movie 4", "7:00 PM", 180, 0},
        {"Movie 5", "10:00 PM", 200, 0}
    };
    Booking bookings[MAX_BOOKINGS];
    int bookingCount = 0;
    while (1) {
        printf("1. Display Movies\n");
        printf("2. Book Ticket\n");
        printf("3. Display Bookings\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayMovies(movies);
                break;
            case 2:
                bookTicket(movies, bookings, &bookingCount);
                break;
            case 3:
                displayBookings(bookings, bookingCount);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
