
! ---------------------------------------------------------------------------- !
!       BOWLING ALLEY. 08/10/16
!
  Room    bowlingAlley "Lowry Lanes"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  switchTimePast();
              }
              iAskWait = 0;
              iAskSecondWait = 0;
              SelfPlayer.outside = false;
              print "Thick smoke hangs in the air of the bowling alley. ";
              if (bowlingAlleyKids in self) print "At the entrance, two kids play an arcade machine. ";
              else print "An arcade machine sits at the entrance. ";
              print "On the west side of the building, there's a bar";
              if (self.pastFirstTime) print ". Sam's not there.";
              else print " and an older guy works behind the counter.";
              self.pastFirstTime = false;
              print " On the east side, a girl handles equipment rental. ";
              if (basement.firstTime == false) print "The way out is south. ";
              "Next to the far lane a backdoor, painted red like the walls, leads north.";
          ],
          n_to [;
              <<Enter bowlingAlleyBackDoor>>;
          ],
          s_to [;
              <<Enter bowlingAlleyFrontDoor>>;
          ],
          e_to [;
              <<Enter bowlingAlleyEquipmentRental>>;
          ],
          w_to [;
              <<Enter bowlingAlleyBar>>;
          ],
          cant_go [;
              if (basement.firstTime) "You can go east to the equipment rental, west to the bar, or north out the backdoor.";
              "You can go east to the equipment rental, west to the bar, north out the backdoor, or south out the entrance.";
          ],
          before [;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "Balls crack into pins as a few people bowl.";
              Smell:
                  "Cigarette smoke annihilates your nostrils. You wonder how people can breathe.";
              Exit:
                  if (noun == bowlingAlleyBackDoor) <<Enter bowlingAlleyBackDoor>>;
                  <<Enter bowlingAlleyFrontDoor>>;
              WaveHands:
                  "No one pays any attention to you.";
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          pastFirstTime true;

! 08/10/16

  RoomObj -> bowlingAlleyObj "bowling alley"
    with  name 'bowling' 'alley' 'area' 'place',
          description [;
              <<Look bowlingAlley>>;
          ],
          before [;
              Search:
                  "This is a big place. You'd look strange searching it.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/10/16

  Object  -> bowlingAlleyKids "kids"
    with  name 'boy' 'boys' 'kids' 'kid' 'child' 'children' 'little' 'big' 'bigger',
          describe [;
              rtrue;
          ],
          before [;
              AskCreatureFor, AskTo:
                  if (KidHit()) rtrue;
              Attack, Kick:
                  return L__M(##Attack, 1);
              Enter, Go:
                  "You're already here.";
              Examine:
                  "The two boys are engrossed in the game. The little one watches while the bigger one plays.";
              Talk:
                  if (KidHit()) rtrue;
              Hello:
                  if (KidHit()) rtrue;
              PushDir, Push, Pull, Search:
                  "You don't need to cause a scene like that.";
              WaveObject:
                  "The kids don't notice. Their backs are towards you.";
          ],
          life [;
              Kiss:
                  "That's just wrong.";
              default:
                    if (KidHit()) rtrue;
          ],
          orders [;
              if (KidHit()) rtrue;
          ],
    has   animate male pluralname concealed;

! 08/11/16

  OutRch  -> bowlingAlleyGirl "teen"
    with  name 'person' 'woman' 'girl' 'punk' 'nancy' 'mohawk' 'dyed' 'platinum' 'blonde' 'teen' 'attendant' 'chick' 'lady',
          describe [;
              rtrue;
          ],
          before [;
              Examine:
                  "The punk is sporting a mohawk dyed platinum blonde. Bored, she plays with the cash register.";
              Enter, Go:
                  print "You walk over to the girl.^";
                  <<Enter bowlingAlleyEquipmentRental>>;
              WaveObject:
                  "She either waves you over or flips you off. It's hard to tell from here.";
          ],
          life [;
              "You can't do that from here.";
          ],
          orders [;
              "You can't do that from here.";
          ],
    has   animate female scenery;

! 08/11/16

  OutRch  -> bowlingAlleyBartender "bartender"
    with  name 'bartender' 'man' 'male' 'guy' 'phil' 'old' 'older' 'cigarette' 'cigarettes' 'cig' 'cigs' 'fag' 'fags' 'smokes',
          describe [;
              rtrue;
          ],
          before [;
              Examine:
                  if (bowlingAlleyBar.firstTime) {
                      bowlingAlleyBar.firstTime = false;
                      "The bartender stands behind the bar, washing some glasses.
                      It's not Judy, and Sam's not there.";
                  }
                  "The bartender stands behind the bar, washing some glasses. He looks busy
                  and tries to sneak in a hit of a cigarette now and then.";
              Enter, Go:
                  print "You walk over to the bartender.^";
                  <<Enter bowlingAlleyBar>>;
              WaveObject:
                  "He doesn't look up from what he's doing.";
          ],
          life [;
              "You can't do that from here.";
          ],
          orders [;
              "You can't do that from here.";
          ],
    has   animate male scenery;

! 08/10/16

  Object  -> bowlingAlleyArcadeMachine "arcade machine"
    with  name 'arcade' 'machine' 'game' 'demo' 'screen' 'asteroids' 'print' 'cabinet',
          before [;
              Examine, Search:
                  if (self.seenFirstTime) {
                      self.seenFirstTime = false;
                      print "The arcade cabinet is something from the '80s if you're not mistaken. ";
                  }
                  print "~Asteroids~ is written in large print on the side. ";
                  if (bowlingAlleyKids in bowlingAlley) "Two kids crowd out the screen.";
                  "The game cycles through its demo since no one is playing it.";
              Play:
                  if (bowlingAlleyKids in bowlingAlley) "The kids block the machine and are not about to move.";
                  "Something about this game. Hmm. No time to play.";
              Open:
                  if (bowlingAlleyKids in bowlingAlley) "The kids block the machine and are not about to move.";
                  "You could try to open it and get the quarters, but you don't need that kind of trouble.";
              Close:
                  if (bowlingAlleyKids in bowlingAlley) "The arcade machine isn't open. Two kids play it.";
                  "The arcade machine isn't open.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The arcade machine doesn't need to go anywhere.";
          ],
          seenFirstTime true,
     has  concealed static container open;

! 08/10/16

  Object  -> bowlingAlleyFrontDoor "double doors"
    with  name 'front' 'door' 'doors' 'glass' 'entrance' 'double' 'parking' 'lot' 'cars' 'car',
          before [;
              Enter, Go:
                  if (basement.firstTime) "Not without finding out what is going on.";
                  parkingLot.outOfAlley = true;
                  PlayerTo(parkingLot);
                  rtrue;
              Examine, Search:
                  "The doors to the alley look out into the parking lot. There are a few cars parked in front of the place.";
              Close, Open:
                  "They're automatic and don't work like that.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the alley.";
          ],
     has  concealed static pluralname;

! 08/11/16

  OutRch  -> bowlingAlleyBar "bar"
    with  name 'bar' 'westside' 'counter',
          before [;
              Enter, Go:
                  PlayerTo(alleyBar);
                  rtrue;
              Examine:
                  print "The bar's empty. With no customers to help the bartender cleans some glasses";
                  if (self.firstTime) {
                      self.firstTime = false;
                      ". But it's not Judy.";
                  }
                  ".";
          ],
          firstTime true;

! 07/16/20

  OutRch  -> bowlingAlleyGlasses "glasses"
    with  name 'glasses' 'dishes' 'bin' 'tub',
          before [;
              Enter, Go:
                  PlayerTo(alleyBar);
                  rtrue;
              Examine:
                  "The bartender fishes them out of a tub, cleaning the glasses before putting them up.";
          ],
    has   pluralname;

! 08/11/16

  OutRch  -> bowlingAlleyEquipmentRental "equipment rental"
    with  name 'equipment' 'rental' 'counter' 'cash' 'register' 'eastside',
          before [;
              Enter, Go:
                  PlayerTo(alleyRental);
                  rtrue;
              Examine:
                  "Nobody's up at the counter right now. The girl that runs the register stands there messing with it.";
          ],
          firstTime true;

! 01/02/18

  OutRch  -> bowlingAlleyCustomers "customers"
    with  name 'customer' 'customers' 'people' 'pitcher' 'pitchers' 'drink' 'drinks',
          before [;
              Examine:
                  "Talking to themselves by the lanes, the few people here are always smoking and drinking harder than bowling.";
              Enter, Go:
                  "They seem content to themselves, and they've always been cliquish.";
                    Attack, Burn, Cut, Kick, Push, PushDir, Pull:
                  "Violence isn't the answer to this one.";
              Wave, WaveObject:
                  "You wave, but no one cares.";
              default:
                  "They seem content to themselves, and they've always been cliquish.";
          ],
          life [;
              "They seem content to themselves, and they've always been cliquish.";
          ],
          orders [;
              "They seem content to themselves, and they've always been cliquish.";
          ],
     has  pluralname animate scenery;

! 08/10/16

  OutRch  bowlingAlleyBackDoor "backdoor"
    with  name 'back' 'door' 'backdoor',
          before [;
              Enter, Go:
                  if (self.enterFristTime) {
                      self.enterFristTime = false;
                      print "Giving it a minute you slip out the backdoor without anybody noticing.^";
                  }
                  parkingLot.outOfAlley = true;
                  iNancyConversation = 0;
                  PlayerTo(backLot);
                  rtrue;
              Examine:
                  print "The backdoor is in the far ";
                  if (self in bowlingAlley) print "northeast";
                  else print "north";
                  " corner. It's painted red to disguise it, blending in with the walls.";
          ],
          enterFristTime true,
          found_in bowlingAlley alleyRental;

! 08/11/16

  OutRch  alleyBarEntrance "alley"
    with  name 'entrance' 'arcade' 'machine' 'bowling' 'alley' 'alleys',
          before [;
              Enter, Go:
                  if (alleyBarStool.sitOn) {
                      alleyBarStool.sitOn = false;
                      print "(first getting off the stool)^";
                  }
                  iNancyConversation = 0;
                  PlayerTo(bowlingAlley);
                  rtrue;
              Examine:
                  print "The alley's pretty empty";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print " tonight";
                  ", but a few customers sit around drinking and bowling.";
          ],
          found_in alleyBar alleyRental;

! 01/02/18

  OutRch  alleyBarLane "lane"
    with  name 'far' 'lane' 'lanes',
          before [;
              Examine:
                  if (self in alleyBar) "Bowling alley lanes fill the north half of the building.";
                  "Bowling alley lanes fill the north half of the building. Over by the far east lane,
                  there's a backdoor out of here.";
          ],
          found_in alleyBar alleyRental bowlingAlley;

! 01/02/18

  OutRch  bowlingAlleyWall "wall"
    with  name 'red' 'wall' 'walls' 'mural',
          before [;
              Enter, Go:
                  "You're already here.";
              Examine:
                  "The walls are red, but there's a mural on the west side. It's a single tone print, done in white, of a ball crashing into some pins. Next to it someone drew Kilroy, but it says ~The Dude Was Here~ instead.";
          ],
          found_in alleyBar alleyRental bowlingAlley;

! 09/07/20

  OutRch  bowlingAlleyKilroy "kilroy"
    with  name 'kilroy' 'drawing',
          before [;
              Enter, Go:
                  "You're already here.";
              Examine:
                  "Kilroy is a simple drawing of a bald person looking over a wall with a long nose. Hands grip the wall on either side.";
              Rub:
                  "You don't need to clean him up. He's kind of cute.";
          ],
          found_in alleyBar alleyRental bowlingAlley,
          has proper;

! 07/28/19

  OutRch  bowlingAlleySmoke "smoke"
    with  name 'smoke' 'light' 'lights',
          before [;
              Examine:
                  "Smoke hangs in the air, illuminated by the lights.";
          ],
          found_in alleyBar alleyRental bowlingAlley;


! 01/10/18

  OutRch  alleyBarCustomers "customers"
    with  name 'customer' 'customers' 'people' 'pitchers' 'drinks' 'drink',
          before [;
              Examine:
                  "Talking to themselves by the lanes, the few people here are always smoking and drinking harder than bowling.";
              Enter, Go:
                  "They seem content to themselves, and they've always been cliquish.";
              Wave, WaveObject:
                  "You wave, but no one cares.";
              default:
                  "They seem content to themselves, and they've always been cliquish.";
          ],
          life [;
              "They seem content to themselves, and they've always been cliquish.";
          ],
          orders [;
              "They seem content to themselves, and they've always been cliquish.";
          ],
          found_in alleyBar alleyRental,
     has  pluralname animate scenery;

! 10/03/19

  ORchGoneKids  bowlingAlleyGoneKids "kids"
    with  name 'boy' 'boys' 'kids' 'kid' 'child' 'children' 'little' 'big' 'bigger' 'bully',
          before [;
              Examine:
                  "You can't see them anymore.";
              Follow:
                  "Not without finding out what is going on.";
              default:
                  "You can't see them anymore.";
          ],
          life [;
              "You can't see him anymore.";
          ],
     has  animate male pluralname scenery;
