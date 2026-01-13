#include <stdio.h>
#include <unistd.h>   // For read() and STDIN_FILENO
#include <termios.h>  // For terminal attributes

// Function to configure the terminal
void set_raw_mode(int enable) {
    static struct termios oldt, newt;

    if (enable) {
        // 1. Get current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // 2. Disable Canonical Mode (buffering) and Echo
        newt.c_lflag &= ~(ICANON | ECHO);

        // 3. Apply the new settings immediately
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    } else {
        // Restore old settings
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
}

void func() {
    int c;
    
    set_raw_mode(1); // Enable instant input
    
    // We use standard getchar() now, but the terminal behaves differently!
    while ((c = getchar()) != EOF) {
        printf("putchar call\n");
        putchar(c);
    }

    set_raw_mode(0); // Good practice: restore settings before exiting
}

int main() {
    func();
    return 0;
}