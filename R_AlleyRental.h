
! ---------------------------------------------------------------------------- !
!       ALLEY RENTAL. 08/11/16
!
  Room    alleyRental "Equipment Rental"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  StartDaemon(alleyRentalNancy);
                  iRoom++;
              }
              SelfPlayer.outside = false;
              print "Shoes fill the racks lining the back wall. It's been ";
              if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print "a slow night";
              else print "slow";
              print ". A bored teen works the counter. No one else is here. The few customers in the place are already bowling.
              To the west, the entrance for the alley. North, the backdoor out of here.";
              print "^^Behind the counter, the teen ";
              if (alleyRentalNancy.angry) print "glares at";
              else print "watches";
              print " you while playing with the cash register - a can of freshener by her side";
              if (self.talkFirstTime) {
                  self.talkFirstTime = false;
                  alleyRentalNancy.askIntroQuestion = true;
                  ".^^~Like. Did you know you can spell 'hell' using numbers on a keypad?
                  You have to look at it upside down, but it's pretty cool.~";
              }
              ".";
          ],
          w_to [;
              <<Enter alleyBarEntrance>>;
          ],
          n_to [;
              <<Enter bowlingAlleyBackDoor>>;
          ],
          cant_go [;
              "You can go west towards the entrance or north out the backdoor.";
          ],
          before [;
              Exit:
                  <<Enter alleyBarEntrance>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "Balls crack into pins as a few people bowl.";
              Smell:
                  "Cigarette smoke annihilates your nostrils. You wonder how people can breathe.";
              WaveHands:
                  "No one pays any attention to you.";
              Sorry:
                  <<Answer t_sorry alleyRentalNancy>>;
              Yes:
                  <<Answer t_yes alleyRentalNancy>>;
              No:
                  <<Answer t_no alleyRentalNancy>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          talkFirstTime true;

! 08/11/16

  RoomObj -> alleyRentalObj "room"
    with  name 'room' 'area' 'equipment' 'rental' 'place',
          description [;
              <<Look alleyRental>>;
          ],
          before [;
              Search:
                  "This is a big place, and you'd look strange searching it.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/11/16

  Object  -> alleyRentalCounter "counter"
    with  name 'counter',
          before [;
              Climb, JumpOver:
                  "Everybody in the place would see you. What are you trying to do? Make a scene?";
              Examine, Search:
                  "There's a counter between you and the teen.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the alley.";
          ],
     has  concealed supporter static;

! 08/15/16

  Object  -> alleyRentalFreshnes "freshener"
    with  name 'freshener' 'can' 'spray' 'red' 'white',
          before [;
              Examine, Search:
                  "Out on the counter, a can of freshener sits next to the teen. It looks generic, painted red with blocky white lettering.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "~Get your hands off that,~ she says, slapping you away.";
          ],
     has  concealed static;

! 08/15/16

  Object  -> alleyRentalRegister "register"
    with  name 'register' 'cash' 'keypad' 'pad' 'keys',
          before [;
              Examine, Search:
                  "The teen stands behind the register, tapping her nails on the keypad and paying more attention to the display than you.";
              Close, Open, Take, Remove, Turn, PushDir, Push, Pull:
                  if (self.registerFirstTime) "~I told you to stop.~";
                  self.registerFirstTime = true;
                  "~Don't make me call the cops. They're not my scene,~ she says, staring you down.";
          ],
          registerFirstTime false,
     has  concealed openable open static;

! 06/12/20

  Object  -> alleyRentalDisplay "display"
    with  name 'display' 'number' 'numbers' 'hell',
          before [;
              Examine, Search:
                  "The display reads 7734. When you look at it upside down, it does look a lot like hELL.";
              Turn, PushDir, Push, Pull:
                  "~Leave the register alone. You're going to damage it.~";
              Take, Remove:
                  "There's no need to break it off. It's part of the register.";
              default:
                  "You can't do that.";
          ],
     has  concealed static;

! 08/15/16

  OutRch  -> alleyRentalShoes "rack"
    with  name 'shoes' 'shoe' 'rack' 'racks',
          before [;
              Buy, Rent:
                  if (self.shoesSecondTime) "~If you got the money, put it on the counter. It's a buck an hour for shoe rental and 50 cents a game.~";
                  if (self.shoesFirstTime) {
                      self.shoesSecondTime = true;
                      "~Ok. Like. It's a buck an hour for shoe rental and 50 cents a game. When you get it come on back.~";
                  }
                  if (alleyRentalNancy.askAboutBowling) self.dontKillAskAboutBowling = true;
                  alleyRentalNancy.askAboutBowling = true;
                  self.shoesFirstTime = true;
                  "~Are you really going to bowl? Cause. Like. It's not free.~";
              Examine:
                  "The shoe rack behind the teen is mostly full. The few pairs missing have been lent out to the people in the alley.";
          ],
          shoesFirstTime false,
          shoesSecondTime false;

  Include "NPC_Nancy";
