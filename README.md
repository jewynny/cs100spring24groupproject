 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
## Spotilike - Music Recommender
 
Authors: [Mathew Winkles](https://github.com/Mathyu03), [Janelle Gwynn](https://github.com/jewynny), [Joseph Caraan](https://github.com/jczy3), [Fiona Ye](https://github.com/fionaye3)

## Project Description (Phase I)

### Why is it important to us?
* Music is a big part of our group members' lives, and we would like to connect to others through music, as well as ourselves
### What languages/tools/technologies do we plan to use?
* Our backend will be programmed using C++
* We plan to use the Spotify API to manipulate playlists, using songs and their respective metadata
### What will be the input/output of your project?
* Output will prompt user to create a user profile 
* Alternatively, the user can link their spotify account to skip this step (if applicable)
* Afterwards, the program will collect data of the users favorite songs/genres/producers/etc.
* User will get output for a list of 10 recommended songs based on the input from the previous steps
* User can either continue and get more songs in increments of 10, or choose to make another user profile, repeating the same steps as before
* If there are 2 user profiles in the system, user has the option to compare these profiles. They will receive an output for a playlist of another 10 songs, matching the preferences of both combined users.
### What are the features that the project provides?
* Ability to make multiple user profiles with favorite songs/genres/producers/etc. (User profile class with individual characteristics/variables)
* Recommends similar songs based on the users music preferences (Pulled from spotify API, matching the characteristics outlined above)
* Can compare music tastes with other users by creating a merged playlist with similar vibes (Finds matches between two user profiles, and pulls from spotify API using combined characteristics)

## Design Document (Phase II)

* Epics and user stories can be seen in the projects tab

### Navigation Diagram / User Interface Specification
![image](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/ab02d697-d7cd-4d8c-b357-3916645314db)

### Screen Layouts
* Messages and text are STC, but this will give the general idea of what the screens will look like in the terminal.
```
// Welcome Screen Menu
Welcome! Song Recommender

// Users
Start by creating a user profile
-----------------------------------------------
Name :
Favorite Song :
Playlist Name :

-----------------------------------------------
// Make Playlist
Hello <user name>
Do you want to make a playlist? Y/N :
-----------------------------------------------
// Reccomendations
Song Recommendations Based on Your Fave Song
-----------------------------------------------
1. song 1
2. song 2
...
10. song 10

Which songs would you like to add (enter each 
corresponding # and enter "done" when completed)

Playlist : (users playlist name)
-----------------------------------------------
1. song 1                     Author 1, Album 1
2. song 2                     Author 2, Album 2

*********************
total duration : 455s

Actions
1. remove song
2. ask for more reccomendations
3. finish playlist
4. start new playlist
```

### Class Diagram (UML)
<img width="436" alt="Screenshot_2024-02-16_at_3 47 15_PM" src="https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/0d27a220-3ae5-4d76-8409-567020c470d8">


### Class Diagram Description
* A user class is needed to use the program. Each user has a name to identify them as well as a favorite song. The faveSong string is for giving a basis for recommendations for the user later on. The member functions consist of setters for the name and faveSong (setName, setFaveSong). There also are functions for making a playlist (makePlaylist, discussed in next bullet point) and one for viewing all the playlists the user has made (viewPlaylists).
* The playlist class is something that can be made by the user. It has a HAS-A relationship with the user, a User can have a a Playlist. Each playlist has a name (playlistName) and it consists of a list of song objects (list<Song*>). The member functions of a playlist consist of printSongs to print all the songs in the playlist, addSong to add a song to the playlist, removeSong to remove a song from the playlist, getRecommendations to get 10 songs based off the users interests, and setPlaylistName for a setter for the object.
* The song class has a composition relationship with playlist. This is becuase within the functionality of our program, you can't have a song by itself, it will be in a playlist or have no functionality. Each song has a genre, duration, producer, and album. The member functions within song print the aforementioned variables.
* Lastly, there is a Recommendations class. It has a dependency relationship with Playlist, since Playlist returns the recommendations in one of its member functions. It consists of a list of songs as well, but these are fixed to 10 at a time. You can do the same thing with these songs as the ones from the songs class, however it has an added member function addToPlaylist. This is for if the user likes one or more of the recommendations and wants to add it to a playlist they own.

 
## Development/Testing (Phase III)

### Updated UML class diagram w/ SOLID
![J1eo0aD](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/90de8e4c-1a7b-4620-9d85-3f71427e55ff)
* The first change we made to our class diagram was removing setters/getters from the diagram. We did so because they added excess noise from the diagram. Now, classes only show their fields and methods which is much cleaner. This change didn't require applying SOLID principles. We also updated our UML diagram to reflect design changes we made in our program.
* We also updated the class diagram by removing the makePlaylist function from User. This is because before, it was violating the single responsibility principle (SRP). The user's job is to hold its playlists, not make them. So, we moved makePlaylist to the Playlist class where it belongs, since that is the classes job to handle playlists.
* Similarly, we moved the getRecommendations function from the Playlist class to the Recommendation class. The playlist class violated SRP since it was managing both playlists and recommendations. Now, functions are not needlessly mixed up and everything is more organized. By standardizing the vocabulary, stakeholders for example (or for us, all project members) can better understand the expectations for the respective classes. The code becomes better since there are fewer difficulties arising from needless interdependencies. 
* Lastly, we removed the addToPlaylist function from the Recommendations class, since it was violating SRP as well. We moved it to the Playlist class instead so that each class only has one responsibility, and don't overlap with eachother. Much like the last change, the respective classes are both more concise and organized.

## Final Deliverable (Phase IV)

### Updated UML class diagram (3/15/2024)
<img width="452" alt="Screenshot_2024-03-15_at_12 12 10_AM" src="https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/d140e9ab-d7cc-424e-9abb-f64a30923c7b">

 
 ## Screenshots
 ![6fYUMu5](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/fe5387f2-8534-451c-9913-f841b126d145)
 ![ZB8Ods8](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/e9b1da06-3c12-4e94-88e4-b43efabec0c6)
 ![6N096xJ](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/21c6fdcf-582c-42a1-8540-de41ac595d06)
 ![image](https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024/assets/99463753/0ce05b13-23c4-463f-857c-cb814293bf80)

 ## Installation/Usage
 * To begin, simply clone this repository (git clone --recurse-submodules https://github.com/cs100/final-project-mwink004-jhamo001-jcara025-wye024.git) Then run the commands: "cmake ." , "make" and run the playlist executable with "./playlist".
 ## Testing
 * We did unit tests in our test/test.cpp file with google test. Everyone wrote tests for the code they wrote and then merged it in to the file. We made sure to check the tests before pushing in our functions.
 
