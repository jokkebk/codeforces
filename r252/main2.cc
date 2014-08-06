#include <iostream>
#include <map>

using namespace std;

int main() {
    int trees, pickRate, total = 0, day, fruit, capacity, lastDay, leftover = 0;
    map<int,int> picked;

    cin >> trees >> pickRate;

    //cout << trees << " trees, " << pickRate << " pick rate" << endl;

    for(int i=0; i<trees; i++) {
        cin >> day >> fruit;

        if(picked.find(day) != picked.end()) { // already picked some this day
            picked[day] += fruit;
        } else { // brand new day
            picked[day] = fruit;
        }
    }

    for(auto it = picked.begin(); it != picked.end(); ++it) {
        capacity = pickRate;
        day = it->first;
        fruit = it->second;

        //cout << "Day " << day << " with " << fruit << " fruit and " << leftover << " leftover" << endl;

        if(leftover) { // handle leftovers
            total += leftover;
            capacity -= leftover;

            if(lastDay + 1 != day) // second day already gone
                capacity = pickRate; // replenish
        }

        //cout << total << " fruit picked, " << capacity << " capacity left for today" << endl;

        total += min(fruit, capacity);

        if(fruit > capacity) {
            leftover = min(fruit - capacity, pickRate); // cull to capacity
            lastDay = day;
        } else {
            leftover = 0;
        }
    }

    total += leftover;

    cout << total;

    return 0;
}
