#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    ifstream inFile;
    int i = 0;
    Graph g;

    inFile.open("bestHike.txt");
    vector<string> hikingPath;
    //if(inFile.good([i][j]))
    if(inFile.good())
    {
        if (inFile.is_open())
        {
            string line;
            string trail;
            int linecounter = 0;

            while (getline (inFile,line))
            {
                stringstream POIstream(line);

                if (linecounter == 0)
                {
                    getline(POIstream, trail, ',');
                    while(getline(POIstream, trail, ','))
                    {
                        hikingPath.push_back(trail);
                        g.addVertex(trail);
                    }
                }
                else
                {
                    string temp;
                    int distValue;
                    int numCounter = 0;
                    getline(POIstream, temp, ',');
                    while(getline(POIstream, temp, ','))
                    {
                        distValue = stoi(temp);
                        if (distValue != 0 && distValue != -1)
                        {
                            g.addEdge(hikingPath[linecounter-1], hikingPath[numCounter], distValue);
                        }
                        numCounter++;
                    }
                }
                linecounter++;
                }

            //g.assignDistricts();

            while(input != "6")
            {
            cout<<"======Main Menu======"<<endl;
            cout<<"1. Print points of interest"<<endl;
            cout<<"2. Find shortest path"<<endl;
            cout<<"3. Find shortest distance"<<endl;
            cout<<"4. Backpacking"<<endl;
            cout<<"5. Find how long your hike will take"<<endl;
            //cout<<"6. How much water to bring"<<endl;
            cout<<"6. Quit"<<endl;
            cin>>input;

            if(input == "1")
            {
                //g.assignDistricts();  should print -1
                int m;
                for (int i=0; i<hikingPath.size()-1;i++)
                {
                    cout<<hikingPath[i]<<", ";
                    m=i;
                }
                cout<<hikingPath[m+1]<<endl;
                g.assignDistricts();      //should update to district numbers
            }

            if(input == "2")
            {
                string trailhead;
                string trailEnd;
                cout<<"Enter a starting point of interest:"<<endl;
                cin.ignore(1, '\n');
                getline(cin, trailhead);
                cout<<"Enter an ending point of interest:"<<endl;
                getline(cin, trailEnd);
                bool bothfound = false;
                for(int i =0; i < hikingPath.size();i++)
                {
                    if (hikingPath[i] ==trailhead)
                    {
                        for(int i = 0; i < hikingPath.size();i++)
                        {
                            if (hikingPath[i] == trailEnd)
                            {
                                bothfound = true;
                                g.shortestPath(trailhead, trailEnd);
                            }
                        }
                    }
                }
                /*if (bothfound == false)
                {

                }*/
            }

            if(input == "3")
            {
                string trailhead;
                cout << "Enter where you are:" << endl;
                cin.ignore(1, '\n');
                getline(cin, trailhead);
                string trailEnd;
                cout << "Enter the destination:" << endl;
                getline(cin, trailEnd);
                bool bothfound = false;
                for (int i=0; i < hikingPath.size(); i++){
                    if (hikingPath[i] == trailhead){
                        for (int i=0; i < hikingPath.size(); i++){
                            if (hikingPath[i] == trailEnd){
                                bothfound = true;
                                g.shortestDistance(trailhead, trailEnd);
                            }
                        }
                    }
                }
                if (bothfound == false){
                    cout << "One or more points of interest doesn't exist, or it is not in our database." << endl;
                }
            }

            if(input == "4")
            {
                string trailhead;
                cout << "Enter where you are:" << endl;
                cin.ignore(1, '\n');
                getline(cin, trailhead);
                bool found = false;
                for (int i=0; i < hikingPath.size(); i++)
                {
                    if (hikingPath[i] == trailhead)
                    {
                        found = true;
                    }
                }
                if (found == false)
                {
                    cout << "The point of interest you entered is not in our database." << endl;
                }
                else{
//
                }
            }

            if (input == "5")
            {
                //g.time(c);
            }
/*
            if (input=="6")
            {
                string trailhead;
                string trailEnd;
                cout<<"Enter a starting point of interest:"<<endl;
                cin.ignore(1, '\n');
                getline(cin, trailhead);
                cout<<"Enter an ending point of interest:"<<endl;
                getline(cin, trailEnd);
                bool bothfound = false;
                for(int i =0; i < hikingPath.size();i++)
                {
                    if (hikingPath[i] ==trailhead)
                    {
                        for(int i = 0; i < hikingPath.size();i++)
                        {
                            if (hikingPath[i] == trailEnd)
                            {
                                bothfound = true;
                                //g.water(trailhead, trailEnd);
                            }
                        }
                    }
                }

            }
    */

        }

        inFile.close();
        cout<<"Go take a hike!"<<endl;
        return 0;
        }
    }
}
