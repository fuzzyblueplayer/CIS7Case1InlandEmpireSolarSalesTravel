#include "City.h"

using namespace std;

void generateTrips(City[],int,int);
int calcPrice(City[],int);
void adjMatrix(City[],int);
void adjList(City[], int);


int main() {

    City RS("RS", 0, 16, 33, 24);
    City MV("MV", 16, 0, 26, 18);
    City HE("HE", 33, 26, 0, 30);
    City PE("PE", 24, 18, 30, 0);
    //City arr1[] = { RS,MV,HE,PE };
    City arr1[] = {HE, RS, PE , MV};
    adjMatrix(arr1, 4);
    adjList(arr1, 4);
    generateTrips(arr1, 0, 4);


	system("pause");
	return 0;
}

void adjList(City arr[], int size) {
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i].getCity() << " is adjacent to: ";
        for (int j = 0; j < size; j++) {
            if (arr[i].getDistance(arr[j].getCity()) != 0) {
                cout << arr[j].getCity() << " ";
            }
        }
        cout << endl;
    }
}

void adjMatrix(City arr[],int size) {
    cout << "Adjacency Matrix: " << endl;
    cout << "X " << arr[0].getCity() << " " << arr[1].getCity() << " ";
    cout << arr[2].getCity() << " " << arr[3].getCity() << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i].getCity()<< " " <<arr[i].getDistance("RS") << " " << arr[i].getDistance("MV") << " ";
        cout << arr[i].getDistance("HE") << " " << arr[i].getDistance("PE") << endl;
    }
}

int calcPrice(City trip[],int size) {
    int price = 0;
    for (int i = 0; i < size-1; i++) {
        price += trip[i].getDistance(trip[i+1].getCity());
    }
    return price;
}

void generateTrips(City arr[],int choice,int size) {
    City* tripPrice = new City[size+1];
    cout << "Genereted Trips:" << endl;
    for (int i = 0; i < size; i++) {
        if (choice == i) {
            for (int j = 0; j < size; j++) {
                if (j != i) {
                    for (int k = 0; k < size; k++) {
                        if (k != j && k != i) {
                            for (int l = 0; l < size; l++) {
                                if (l != k && l != j && l != i) {
                                    tripPrice[0] = arr[i];
                                    tripPrice[1] = arr[j];
                                    tripPrice[2] = arr[k];
                                    tripPrice[3] = arr[l];
                                    tripPrice[4] = arr[i];
                                    cout << tripPrice[0].getCity() << "--> ";
                                    cout << tripPrice[1].getCity() << "--> ";
                                    cout << tripPrice[2].getCity() << "--> ";
                                    cout << tripPrice[3].getCity() << "--> ";
                                    cout << tripPrice[4].getCity() << " " << calcPrice(tripPrice,size+1) << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}