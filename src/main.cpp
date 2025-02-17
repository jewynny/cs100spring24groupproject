#include "../header/Song.hpp"
#include "../header/Playlist.hpp"
#include "../header/Recommendations.hpp"
#include "../header/User.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// functions 
void createProfileMenu(User &user);
void makePlaylistMenu(User &user);
void displayMenu(User user);
char validateInput(char choice);
void deleteSongs (User user);

int main() {
  // open music.csv file for recommendations
  ifstream inputMusic;
  inputMusic.open("musiclist.csv");
  Recommendations recommendations;
  recommendations.readCSV(inputMusic);
  
  // VARIBLES
  User user;
  char userInput;
  cout << "Welcome to Spotilike Music Recommender! ";

  createProfileMenu(user);
  while(true) {
    displayMenu(user);
    cin >> userInput;
    cin.ignore();
    char choice = validateInput(userInput);
    
      if (choice == '1'){
        makePlaylistMenu(user);
       }
      else if (choice == '2'){
        cout << endl;
        user.viewPlaylists();
      }
      else if (choice == '3'){
        user.addSongToPlaylist(user);
      }
      else if (choice == '4'){
        user.deleteSongs(user);
      }
      else if (choice == '5'){
        recommendations.getRecommendations(); // bugged
      }
      else if (choice == '6'){
        user.showSongsFromPlaylist(user);
      }
      else if (choice == '7'){
        break;
      }
    }
  return 0;
}



char validateInput(char choice) {
    while (choice <= 48 || choice >= 56) {
      cout << "Please enter a valid choice 1-7." << endl;
      cin >> choice;
      cin.ignore();
    }
  return choice;
}

void displayMenu(User user) {
    cout << "\nHello " << user.getName() <<  ", please select an action: " << endl;
    cout << "1. Create a playlist" << endl;
    cout << "2. View playlists" << endl;
    cout << "3. Add songs to playlist" << endl;
    cout << "4. Delete songs from a playlist" << endl;
    cout << "5. Get recommendations" << endl;
    cout << "6. Print songs of a playlist" << endl;
    cout << "7. Quit" << endl;
}

void createProfileMenu(User &user) {
  // VARIABLES
  string userName;
  string faveSong;

  // PROMPT USER
  cout << "Please create a user profile.\n";
  cout << "Name: ";
  getline(cin, userName);
  cout << "Profile \"" << userName << "\" created." << endl;

  // SET USER PROFILE
  User newUser(userName);
  user = newUser;
}

void makePlaylistMenu(User& user) {
  // VARIABLES
  string playlistName;

  cout << "\nEnter the name of your playlist: ";
  getline(cin, playlistName);

  user.addAPlaylist(playlistName);
}

