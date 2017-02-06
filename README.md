Simon-ConCATination
===================

# Overview
This project was completed as part of the Lafayette College Software Engineering course by team ConCATination.  The app was written in C++ using Qt.  It implements the classic game of Simon with a twist - you can configure the color mode (full color, grayscale, or black and white), audio mode (on or off), and input mode (keyboard, mouse, or LEAP Motion controller).  This game is meant to be used for research purposes to determine the effects of each factor on a person's working memory.  Data from each trial is saved to a CSV file to analyze participants' performance under each condition.  Password protection is used to allow only research administrators to configure trial settings.

# Project Structure
## State Machines
The top level project files are the two state machines that manage the game's run loops.  The SimonController class is the main state machine that runs each of the SimonGame instances, which are each configured to one color/audio/input mode.

## Data Model
The data model classes store trial level data (participant information) in the TrialData class and game level data (color/audio/input modes) in the GameData class.

## Physical Interface
Each of the input modes (keyboard, mouse, and LEAP Motion controller) is handled by a separate interface manager class, all of which inherit from the InputManager abstract class.  Classes that require notification upon input events subclass the EventListener abstract class.

## Graphical Interface
The main game UI that displays the Simon game can be found in the SimonUI class.  Additional UI classes implement dialogs that allow research administrators to change the administrator password (ChangePassDialog), enter the administrator password (PassDialog), and set trial and game settings (TrialSettingsDialog).  Additionally, there is a TrialSettingsModel class that handles the table view data for the TrialSettingsDialog class.  The table view shows each of the Simon games that have been configured for a single participant's trial.

# Documentation
View the project documentation [here](http://htmlpreview.github.io/?https://github.com/garrisoh/Simon-ConCATination/blob/master/html/index.html).  The documentation was generated using Doxygen.
