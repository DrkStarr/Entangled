
! ---------------------------------------------------------------------------- !
!       ALLEY BAR. 08/11/16
!
  Room    alleyBar
   with   short_name [;
              if (alleyBarStool.sitOn == false) {
                  print "Bar";
                  rtrue;
              }
              print "Bar ";
              style roman;
              print "(on the stool)";
              rtrue;
          ],
          description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  StartDaemon(self);
                  StartDaemon(alleyBarPhil);
              }
              SelfPlayer.outside = false;
              "The bar is lined with a few stools and runs the length of the room.
              Behind it, rows of empty glasses sit along the back wall. There's also
              a lone bottle of whiskey on the shelf.
              A bathroom lies to the west while the entrance is east.";
          ],
          daemon [;
              if (player in self) {
                  iBarTenderAction++;
                  if (self.shutOffDaemon == false) {
                      if (iBarTenderAction >= 2) {
                          iBarTenderAction = 0;
                          iAlleyBartender++;
                          switch (iAlleyBartender) {
                              1: print "^The bartender looks busy as he washes some glasses";
                              2: print "^The bartender finishes his cigarette. Dying it out in one of the ashtrays only to light up another";
                              3: print "^The bartender drys off a glass before putting it back on the shelf";
                              4: iAlleyBartender = 0;
                                 print "^The bartender reaches into a tub full of water, pulling out a glass to wash";
                          }
                          if (bowlingAlleyBar.firstTime) {
                              bowlingAlleyBar.firstTime = false;
                              print ". And it's not Judy. It's an older man";
                          }
                          if (self.barFirstTime) {
                              self.barFirstTime = false;
                              ".^^~How's it going,~ he asks turning to you.";
                          }
                          ".";
                      }
                  } else {
                      self.shutOffDaemon = false;
                  }
              }
          ],
          w_to [;
              <<Enter alleyBarBathroom>>;
          ],
          e_to [;
              <<Enter alleyBarEntrance>>;
          ],
          u_to [;
              if (alleyBarStool.sitOn) <<GetOff alleyBarStool>>;
          ],
          cant_go [;
              "You can go east towards the entrance.";
          ],
          before [;
              Exit:
                  if (alleyBarStool.sitOn) <<GetOff alleyBarStool>>;
                  <<Enter alleyBarEntrance>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "Balls crack into pins as a few people bowl.";
              Smell:
                  "Cigarette smoke annihilates your nostrils. You wonder how people can breathe.";
              WaveHands:
                  "No one pays any attention to you.";
              Sorry:
                  <<Answer t_sorry alleyBarPhil>>;
              Yes:
                  <<Answer t_yes alleyBarPhil>>;
              No:
                  <<Answer t_no alleyBarPhil>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          echoBarTenderAction true,
          shutOffDaemon false,
          barFirstTime true;

! 12/22/16

  RoomObj -> alleyBarObj "room"
    with  name 'room' 'area' 'place',
          description [;
              <<Look alleyBar>>;
          ],
          before [;
              Search:
                  "This is a big place, and you'd look strange searching it.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 08/11/16

  OutRch  -> alleyBarBathroom "bathroom"
    with  name 'bathroom' 'lavatory' 'washroom' 'head',
          before [;
              Enter, Go, Search:
                  if (basement.firstTime == false) "You don't need to go to the bathroom.";
                  if (alleyBarStool.sitOn) {
                      alleyBarStool.sitOn = false;
                      print "(first getting off the stool)^";
                  }
                  if (basement.firstTime) {
                      if (self.bathroomFirstTime) "You already looked in there. Sam's not here.";
                      self.bathroomFirstTime = true;
                      "You peek into the bathroom, but Sam isn't in there.";
                  }
                  "You don't need to go to the bathroom.";
              Examine:
                  "It's a small unisex bathroom for one.";
          ],
          bathroomFirstTime false;

! 08/11/16

  OutRch  -> alleyBarBottle "bottle"
    with  name 'booze' 'bottle' 'drink' 'liquor' 'whiskey' 'jack' 'daniel' 'daniels' 'daniel^s' 'whisky',
          before [;
              Examine:
                  "A bottle of Jack Daniel's rests on a shelf behind the bar.";
              Buy:
                  if (dollarBill in player || dollarBill in clothes)
                      "Since it causes impaired thinking and slows down motor functions,
                      you shouldn't waste your money on that.";
                  if (alleyBarBeer.tryToBuy) "~I still don't see any money in your hand,~ says the bartender.";
                  alleyBarBeer.tryToBuy = true;
                  "~I don't see any money in your hand,~ says the bartender.";
              Take, Remove:
                  if (self.triedToTake)
                      "~Get back,~ the bartender says, ~I told you. You want something I'll get
                      it for you. But let me see that coin.~";
                  self.triedToTake = true;
                  "~If you want something, I'll get if for you. But you'll have to pay up.~";
          ],
          triedToTake false;

! 01/02/18

  OutRch  -> alleyBarShelf "washed glasses"
    with  name 'shelf' 'shelves' 'empty' 'glass' 'glasses' 'washed',
          before [;
              Examine:
                  "A row of shelves holds beer glasses that have been washed. Most customers prefer the taps.";
              Take, Turn, Remove, Push, Pull, PushDir:
                  "You lean over the bar, reaching out for one.^
                  ^~Stay back,~ the bartender says, splashing water at you.";
          ],
    has   pluralname;

! 01/02/18

  OutRch  -> alleyBarBeer "tap"
    with  name 'tap' 'taps' 'beer' 'pitcher' 'pitchers' 'pint',
          before [;
              Examine:
                  "The taps are the only way this place makes money. Most of the customers sit by
                  the alleys, drinking from pitchers.";
              Buy:
                  if (dollarBill in player || dollarBill in clothes)
                      "Since it causes impaired thinking and slows down motor functions,
                      you shouldn't waste your money on that.";
                  if (self.tryToBuy) "~Don't waste my time. They're a buck a pitcher.~";
                  self.tryToBuy = true;
                  "~Beer 'round here cost a buck a pitcher,~ says the bartender. ~Fork over some cash and I'll pour you one.~";
          ],
          tryToBuy false;

! 01/02/18

  OutRch  -> alleyBarGlasses "dirty glasses"
    with  name 'dirty' 'glass' 'glasses' 'dish' 'dishes' 'tub' 'water' 'bin',
          before [;
              Examine:
                  "Dirty glasses soak in a tub behind the bar. The bartender is constantly
                  washing them, running them under water, and drying them off. He stacks them
                  neatly on the shelf behind him.";
              Buy, Take, Remove:
                  "~You don't want them. I still have to wash them.~";
              Rub:
                  "~Thanks. But I don't need the help.~";
          ],
    has   pluralname;

! 05/21/18

  Object -> alleyBarStool "stool"
    with  name 'stool' 'stools' 'chair' 'chairs',
          before [;
              Enter:
                  if (self.sitOn) "You're already sitting down.";
                  self.sitOn = true;
                  alleyBarPhil.askForDrink = true;
                  "You sit down on one of the stools. ~Can I get you a drink?~ asks the bartender.";
              Examine, Search:
                  "A few stools line the front of the bar.";
              GetOff:
                  if (self.sitOn) {
                      self.sitOn = false;
                      "You get off the stool, pushing it back under the counter.";
                  }
              Take, Remove, Turn, PushDir, Push, Pull:
                  "~What are you doing? Please leave that alone,~ the bartender says.";
          ],
          sitOn false,
     has  concealed static;

! 07/15/19

  OutRch  -> alleyBarCigarette "cigarette"
    with  name 'cigarette' 'cig' 'fag' 'cigs' 'fags',
          before [;
              Go:
                  "It's on the other side of the counter, resting on the edge and out of reach.";
              Examine:
                  "The cigarette rests on the edge of the bar. Every now and then, the bartender picks it up to take a hit off it.";
              Buy, Take, Remove, Turn, PushDir, Push, Pull:
                  "~Get back,~ the bartender says, splashing some water towards you, ~that's mine.~";
          ];

! 08/11/16

  Object -> alleyBarCounter "bar"
    with  name 'bar' 'counter',
          before [;
              Climb, JumpOver:
                  "Everybody in the place would see you. What are you trying to do? Make a scene?";
              Enter, GoBehind:
                  "The bartender stops you, ~What do you think you're doing?~";
              Examine, Search:
                  "The bar is empty. No one is sitting up here. Made out of maple, it has a cash register at one end.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the bar.";
          ],
     has  concealed static supporter;

! 01/03/18

  Object -> -> alleyBarRegister "register"
    with  name 'cash' 'register',
          before [;
              Examine, Search:
                  "The cash register sits at the end of the bar.";
              Open, Close, Take, Remove, Turn, PushDir, Push, Pull:
                  "~Get back,~ the bartender says, shooing you away.";
          ],
     has  concealed static;

  Include "NPC_Phil";
