// main.cpp
// Name: Kayden Vu

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  srand(time(0));
  string user_name;
  int user_input;
  bool game_over = false;
  bool game_victory = false;    
  bool flashlight = false;
  bool dagger = false;
  bool sword = false;
  bool armor = false;
  bool ladder = false;
  int coins = 0;
  int level = 1;
  int experience = 1;
  cout << "Welcome! What's your name?" << endl;
  cin >> user_name;
  while (!(game_over)) { 
    int user_hp;
    int user_damage;
    if (experience / (level * 3) >= 1) {
      experience = experience % (level * 3);
      level++;
      cout << "Congrats! You are now level " << level << endl;
    }
    if (armor) {
      user_hp = 50 + (level * 5);
    } else {
      user_hp = 18 + (level * 2);
    }
    if (sword) {
      user_damage = 3 * (level + 5) - level * 2;
    } else if (dagger) {
      user_damage = 2 * (level + 3) - level;
    } else {
      user_damage = level + 2;
    }
    cout << "Hi, " + user_name +
                ", this is the town center! Make sure to return here often to "
                "shop and make yourself more powerful after battling :)"
         << endl;
    cout << "Where would you like to? \n\t1. Forest (beginner recommended) "
            "\n\t2. The Shop \n\t3. Dragon's Lair (endgame)\n\t4. Check Stats "
            "\n\t5. Exit Game"
         << endl;
    cin >> user_input;
    if (user_input == 1) {
      cout << "You made it to the forest. Would you like to look for a battle "
              "or return to town? \n\t1. Go to forest grounds (beginner "
              "recommended) \n\t2. Go to cave (recommended dagger first) "
              "\n\t3. Return to town."
           << endl;
      int forest_input;
      cin >> forest_input;
      if (forest_input == 1) {
        int bunny_battle;
        int bunny_hp = 10;
        int bunny_damage;
        cout << "You ran into a bunny!" << endl;
        while (user_hp > 0) {
          cout << "\t1. Fight! \n\t2. Run!" << endl;
          cin >> bunny_battle;
          bunny_damage = rand() % 2;
          int user_damage_bunny =
              (rand() % (user_damage - 1)) + (user_damage - 3); 
          if (bunny_battle == 1) {
            user_hp = user_hp - bunny_damage;
            bunny_hp = bunny_hp - user_damage_bunny;
            if (bunny_hp <= 0) {
              cout << "Bunny has been slained. You gain 2 coins." << endl;
              coins += 2;
              experience += 1;
              cout << "You gained one experience points!" << endl;
              cout << "You now have " << coins << " coins." << endl;
              break;
            } else if ((bunny_hp > 0) && (user_hp > 0)) {
              cout << "Bunny did " << bunny_damage << " damage! You now have "
                   << user_hp << " health points. You did " << user_damage_bunny
                   << " damage. Bunny has " << bunny_hp << " health points."
                   << endl;
            } else if (user_hp <= 0) {
              cout << "You got slain by a bunny. Game over." << endl;
              game_over = true;
            }
          } else if (bunny_battle == 2) {
            cout << "You made it out safely!" << endl;
            break;
          } else {
            cout << "Enter either 1 or 2!" << endl;
          }
        }
      } else if (forest_input == 2) {
        if (!(flashlight)) {
          int cave_warning;
          cout << "Warning: The cave requires a flashlight to not get lost."
               << endl;
          cout << "The cave requires a flashlight to venture forward. Do you "
                  "want to continue even without one? \n\t1. Yes \n\t2. No"
               << endl;
          cin >> cave_warning;
          if (cave_warning == 1) {
            cout << "You get lost after venturing further and cannot retrace "
                    "your steps back to town. Which way do you proceed? \t1. "
                    "Left \n\t2. Right"
                 << endl;
            int cave_path;
            bool cave_choice = false;
            cin >> cave_path;
            int cave_luck = (rand() % 2) + 1;
            while (!(cave_choice)) {
              if (cave_path == 1 || cave_path == 2) {
                if (cave_path == cave_luck) {
                  cave_choice = true;
                } else {
                  cout << "You get consumed in the darkness after exploring "
                          "too far and starve to death in the cave. Game over."
                       << endl;
                  game_over = true;
                  break;
                }
              } else {
                cout << "Pick 1 or 2!" << endl;
                cin >> cave_path;
              } 
            }
          }
        }
        if (!(game_over)) {
          int bat_battle;
          int bat_hp = 30;
          int bat_damage;
          cout << "You encountered a bat!" << endl;
          while (user_hp > 0) {
            cout << "\t1. Fight! \n\t2. Run!" << endl;
            cin >> bat_battle;
            bat_damage = (rand() % 4) + 3;
            int user_damage_bat =
                (rand() % (user_damage - 1)) + (user_damage - 3);
            if (bat_battle == 1) {
              user_hp = user_hp - bat_damage;
              bat_hp = bat_hp - user_damage_bat;
              if (bat_hp <= 0) {
                cout << "Bat has been slained. You gain 5 coins." << endl;
                coins += 5;
                experience += 5;
                cout << "You gained five experience points!" << endl;
                cout << "You now have " << coins << " coins." << endl;
                break;
              } else if ((bat_hp > 0) && (user_hp > 0)) {
                cout << "Bat did " << bat_damage << " damage! You now have "
                     << user_hp << " health points. You did " << user_damage_bat
                     << " damage. Bat has " << bat_hp << " health points."
                     << endl;
              } else if (user_hp <= 0) {
                cout << "You’re a vampire now and terrorize the nearby "
                        "villages! Game over."
                     << endl;
                game_over = true;
              }
            } else if (bat_battle == 2) {
              cout << "You made it out safely!" << endl;
              break;
            } else {
              cout << "Enter either 1 or 2!" << endl;
            }
          }
        }
      } else if (forest_input == 3) {
        cout << "Going back to town!" << endl;
      } else {
        cout << "Type one of the options above! (going back to town...)"
             << endl;
      }
    } else if (user_input == 2) {
      int shop_input;
      bool make_choice = false;
      while (!(make_choice)) {
        cout << "Welcome to my shop, " << user_name
             << "! What would you like to buy?" << endl;
        cout << "\t1. Flashlight \n\t2. Ladder \n\t3. Dagger \n\t4. Sword "
                "\n\t5. Armor \n\t6. Leave the shop"
             << endl;
        cin >> shop_input;
        int yes_no;
        if (shop_input == 1 && !(flashlight)) {
          if (coins >= 10) {
            cout << "This flashlight will guide you through the cave. It costs "
                    "10 coins. Do you want to buy it? \n\t1. Yes \n\t2. No"
                 << endl;
            cin >> yes_no;
            if (yes_no == 1) {
              coins = coins - 15;
              flashlight = true;
              cout << "Thank you for your business! Would like like anything "
                      "else? \n\t1. Yes \n\t2. No"
                   << endl;
              cin >> yes_no;
              if (yes_no == 1) {
                continue;
              } else if (yes_no == 2) {
                make_choice = true;
              } else {
                cout << "Choose 1 or 2!" << endl;
              }
            } else if (yes_no == 2) {
              continue;
            } else {
              cout << "Choose 1 or 2!" << endl;
            }
          } else {
            cout << "This flashlight costs 10 coins. You do not have enough."
                 << endl;
          }
        } else if (shop_input == 1 && flashlight) {
          cout << "You already own this!" << endl;
        } else if (shop_input == 2 && !(ladder)) {
          if (coins >= 20) {
            cout
                << "This ladder will help you reach the Dragon's Lair. It "
                   "costs 20 coins. Do you want to buy it? \n\t1. Yes \n\t2. No"
                << endl;
            cin >> yes_no;
            if (yes_no == 1) {
              coins = coins - 20;
              ladder = true;
              cout << "Thank you for your business! Would like like anything "
                      "else? \n\t1. Yes \n\t2. No"
                   << endl;
              cin >> yes_no;
              if (yes_no == 1) {
                continue;
              } else if (yes_no == 2) {
                make_choice = true;
              } else {
                cout << "Choose 1 or 2!" << endl;
              }
            } else if (yes_no == 2) {
              continue;
            } else {
              cout << "Choose 1 or 2!" << endl;
            }
          } else {
            cout << "This ladder costs 20 coins. You do not have enough."
                 << endl;
          }
        } else if (shop_input == 2 && ladder) {
          cout << "You already own this!" << endl;
        } else if (shop_input == 3 && !(dagger)) {
          if (coins >= 25) {
            cout << "This dagger costs 25 coins. Your damage will be "
                    "increased. Do you want to buy it? \n\t1. Yes \n\t2. No"
                 << endl;
            cin >> yes_no;
            if (yes_no == 1) {
              coins = coins - 25;
              dagger = true;
              cout << "Thank you for your business! Would like like anything "
                      "else? \n\t1. Yes \n\t2. No"
                   << endl;
              cin >> yes_no;
              if (yes_no == 1) {
                continue;
              } else if (yes_no == 2) {
                make_choice = true;
              } else {
                cout << "Choose 1 or 2!" << endl;
              }
            } else if (yes_no == 2) {
              continue;
            } else {
              cout << "Choose 1 or 2!" << endl;
            }
          } else {
            cout << "This dagger costs 25 coins. You do not have enough."
                 << endl;
          }
        } else if (shop_input == 3 && dagger) {
          cout << "You already own this!" << endl;
        } else if (shop_input == 4 && !(sword)) {
          if (coins >= 75) {
            cout << "This sword costs 75 coins. Your damage will be "
                    "significantly increased and it will replace the dagger if "
                    "you have it. Do you want to buy it? \n\t1. Yes \n\t2. No"
                 << endl;
            cin >> yes_no;
            if (yes_no == 1) {
              coins = coins - 75;
              sword = true;
              cout << "Thank you for your business! Would like like anything "
                      "else? \n\t1. Yes \n\t2. No"
                   << endl;
              cin >> yes_no;
              if (yes_no == 1) {
                continue;
              } else if (yes_no == 2) {
                make_choice = true;
              } else {
                cout << "Choose 1 or 2!" << endl;
              }
            } else if (yes_no == 2) {
              continue;
            } else {
              cout << "Choose 1 or 2!" << endl;
            }
          } else {
            cout << "This sword costs 75 coins. You do not have enough."
                 << endl;
          }
        } else if (shop_input == 4 && sword) {
          cout << "You already own this!" << endl;
        } else if (shop_input == 5 && !(armor)) {
          if (coins >= 50) {
            cout << "This armor costs 50 coins. Your health will be greatly "
                    "increased at higher levels. Do you want to buy it? \n\t1. "
                    "Yes \n\t2. No"
                 << endl;
            cin >> yes_no;
            if (yes_no == 1) {
              coins = coins - 50;
              armor = true;
              cout << "Thank you for your business! Would like like anything "
                      "else? \n\t1. Yes \n\t2. No"
                   << endl;
              cin >> yes_no;
              if (yes_no == 1) {
                continue;
              } else if (yes_no == 2) {
                make_choice = true;
              } else {
                cout << "Choose 1 or 2!" << endl;
              }
            } else if (yes_no == 2) {
              continue;
            } else {
              cout << "Choose 1 or 2!" << endl;
            }
          } else {
            cout << "This armor costs 50 coins. You do not have enough."
                 << endl;
          }
        } else if (shop_input == 5 && armor) {
          cout << "You already own this!" << endl;
        } else if (shop_input == 6) {
          make_choice = true;
        }
      }
    } else if (user_input == 3) {
      if (ladder) {
        int lair_input;
        cout << "You made it to the Dragon's Lair (armor and sword recommended "
                "to continue) Would you like to proceed? \n\t1. Yes \n\t2. No"
             << endl;
        cin >> lair_input;
        if (lair_input == 1) {
          cout << "You see the princess kidnapped by the dragon!" << endl;
          int end_battle;
          int dragon_hp = 200;
          int dragon_damage;
          while (user_hp > 0) {
            cout << "\t1. Fight! \n\t2. Run!" << endl;
            cin >> end_battle;
            dragon_damage = (rand() % 21) + 10;
            int user_damage_dragon =
                (rand() % (user_damage - 1)) + (user_damage - 3);
            if (end_battle == 1) {
              user_hp = user_hp - dragon_damage;
              dragon_hp = dragon_hp - user_damage_dragon;
              if (dragon_hp <= 0) {
                cout 
                    << "The dragon has been defeated and the princess is saved!"
                    << endl;
                game_over = true;
                game_victory = true;
                break;
              } else if ((dragon_hp > 0) && (user_hp > 0)) {
                cout << "Dragon did " << dragon_damage
                     << " damage! You now have " << user_hp
                     << " health points. You did " << user_damage_dragon
                     << " damage. Dragon has " << dragon_hp << " health points."
                     << endl;
              } else if (user_hp <= 0) {
                cout << "You got roasted to death! Game over." << endl;
                game_over = true;
              }
            } else if (end_battle == 2) {
              cout << "You made it out safely!" << endl;
              break;
            } else {
              cout << "Enter either 1 or 2!" << endl;
            }
          }
        } else if (lair_input == 2) {
          cout << "Returning safely to town!" << endl;
        } else {
          cout << "Type 1 or 2! (returning back to town for you...)" << endl;
        }
      } else {
        cout << "You need a ladder to proceed." << endl;
      }
    } else if (user_input == 4) {
      int inventory_check;
      cout << "You are currently level " << level << "." << endl;
      cout << "You have " << experience << "/" << level * 3
           << " experience points." << endl;
      cout << "You have " << coins << " coins." << endl;
      cout << "Would you like to check what's in your inventory? \n\t1. Yes "
              "\n\t2. No"
           << endl;
      cin >> inventory_check;
      if (inventory_check == 1) {
        cout << "You have the following items:" << endl;
        if (flashlight) {
          cout << " - flashlight" << endl;
        }
        if (ladder) {
          cout << " - ladder" << endl;
        }
        if (sword) {
          cout << " - sword" << endl;
        } else if (dagger) {
          cout << " - dagger" << endl;
        }
        if (armor) {
          cout << " - armor" << endl;
        }
      } else if (inventory_check == 2) {
        cout << "Okay, make sure to check eventually!" << endl;
      } else {
        cout << "Enter 1 or 2!" << endl;
      }
    } else if (user_input == 5) {
      cout << "Hope to see you again! ^_^" << endl;
      return 0;
    } else {
      cout << "Type a valid number 1-5!" << endl;
    }
  }
  if (game_victory) {
    string name_princess;
    int end_choice;
    bool choice = false;
    cout << "Congrats! What is the name of the saved princess?" << endl;
    cin >> name_princess;
    cout << "Princess " << name_princess
         << " thanks you for your service to the kingdom!" << endl;
    cout << "What would you like to do now that you've conquered the dragon? "
            "\n\t1. Ask for the princess's hand in marriage \n\t2. Declare "
            "yourself the new king"
         << endl;
    while (!(choice)) {
      cin >> end_choice;
      if (end_choice == 1) {
        cout << "The princess accepts your proposal! You live happily ever "
                "after."
             << endl;
      } else if (end_choice == 2) {
        cout << "You overthrow the old king and become the new ruler. No one "
                "can stop you! Muahahahahhaha >:)"
             << endl;
      } else {
        cout << "Pick one of the endings!" << endl;
      }
    }
  }
  return 0;
}