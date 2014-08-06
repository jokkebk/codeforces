#include <iostream>
#include <string.h>

using namespace std;

void printB(unsigned int v) {
    for (int i = 31; i >= 0; i--)
        std::cout << ((v >> i) & 1);
}

void printM(unsigned int v) {
    for (int i = 0; i < 25; i++) {
        cout << ((v >> i) & 1);
        if(i % 5 == 4)
            cout << " ";
    }
}

void printInfo(unsigned int *info, int cards) {
    int i;

    for(i=0; i<cards; i++) {
        cout << i << ": ";
        printM(info[i]);
        cout << endl;
    }

    cout << endl;
}

void initInfo(unsigned int *info, unsigned int *hand, unsigned int cards) {
    unsigned int i, mask = 0;

    for(i=0; i<cards; i++)
        mask |= hand[i];

    for(i=0; i<cards; i++)
        info[i] = mask;

    //cout << "Total mask ";
    //printM(mask);
    //cout << endl;
}

// malloc.c or http://www.exploringbinary.com/ten-ways-to-check-if-an-integer-is-a-power-of-two-in-c/
int isPowerOfTwo(unsigned int x) {
  return ((x != 0) && !(x & (x - 1)));
}

bool isComplete(unsigned int *info, unsigned int cards) {
    unsigned int i;

    for(i=0; i<cards; i++)
        if(!isPowerOfTwo(info[i]))
            return false;

    return true;
}

void showColor(unsigned int *info, unsigned int *hand, unsigned int cards, unsigned int color) {
    int i, mask = 0x1F << (color * 5);

    //cout << "Showing color ";
    //printM(mask);
    //cout << endl;

    for(i=0; i<cards; i++) {
        if(hand[i] & mask) // point
            info[i] &= mask; // now we know it's this color
        else // don't point at this
            info[i] &= ~mask; // now we know it's other color
    }
}

void showNumber(unsigned int *info, unsigned int *hand, unsigned int cards, unsigned int number) {
    // 100001000010000100001 = 1082401
    int i, mask = 1082401 << number;

    //cout << "Showing number ";
    //printM(mask);
    //cout << endl;

    for(i=0; i<cards; i++) {
        if(hand[i] & mask) // point
            info[i] &= mask; // now we know it's this color
        else // don't point at this
            info[i] &= ~mask; // now we know it's other color
    }
}

int countShows(unsigned int n) {
    int i, count = 0;

    for(i=0; i<5; i++)
        if(n & (1 << i))
            count++;

    return count;
}

int main() {
    // we number cards from 0-24 and info is a bitmask of possible cards
    unsigned int hand[100], info[100];
    unsigned int i, cards, card, fullMask;
    string str;
    int best = 10;

    cin >> cards;

    for(i=0; i<cards; i++) {
        cin >> str;

        switch(str[0]) {
            case 'R': card = 0; break;
            case 'G': card = 5; break;
            case 'B': card = 10; break;
            case 'Y': card = 15; break;
            case 'W': card = 20; break;
        }

        card += str[1] - '1';
        hand[i] = 1 << card;
    }

    //cout << "Hand:" << endl;
    //for(i=0; i<cards; i++) {
    //    printM(hand[i]);
    //    cout << endl;
    //}
    //cout << endl;

    //initInfo(info, hand, cards);
    //printInfo(info, cards);
    //cout << "Complete: " << isComplete(info, cards);

    //showColor(info, hand, cards, 0);
    //showNumber(info, hand, cards, 0);
    //printInfo(info, cards);
    //cout << "Complete: " << isComplete(info, cards);

    //return 0;

    // Color guess combinations
    for(unsigned int color = 0; color < 32; color++) {
        // Number guess combinations
        for(unsigned int number = 0; number < 32; number++) {
            if(countShows(number) + countShows(color) >= best)
                continue; // don't bother


            initInfo(info, hand, cards);

            for(i=0; i<5; i++)
                if(color & (1 << i))
                    showColor(info, hand, cards, i);

            for(i=0; i<5; i++)
                if(number & (1 << i))
                    showNumber(info, hand, cards, i);

            if(isComplete(info, cards)) {
                //cout << "Best try " << countShows(color) << " / " << countShows(number) << endl;
                best = countShows(number) + countShows(color);
            }
        }
    }

    cout << best;

    return 0;
}
