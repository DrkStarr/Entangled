
! ---------------------------------------------------------------------------- !
!       THE TAVERN. 6/8/17
!
!
!
  Room    theTavern
   with   short_name [;
              if (SelfPlayer.onRiser) {
                  print "The Tavern ";
                  style roman;
                  print "(on the riser)";
                  rtrue;
              }
              if (theTavernStool.sitOn) {
                  print "The Tavern ";
                  style roman;
                  print "(on the stool)";
                  rtrue;
              }
              print "The Tavern";
              rtrue;
          ],
          description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  StartDaemon(self);
                  StartDaemon(theTavernObj);
                  StartDaemon(theTavernNick);
              }
              if (SelfPlayer.onRiser) {
                  "Being on stage doesn't feel different, but no one is in the room right now.
                  Next to you is the Marshall half-stack. In the corner, the mixer that controls the sound.";
              }
              if (theTavernDoor.bartenderReturns && theTavernNick in self) theTavernDoor.bartenderReturns = false;
              SelfPlayer.outside = false;
              self.theTavernEntered = true;
              print "The Tavern is a small bar with enough room for a band, a few chairs and tables,
              the counter, and some stools. There's no band";
              if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print " tonight";
              print ", but upon the riser is a Marshall half-stack. The front doors out of this place are north.^";
              if (theTavernNick in self) {
                  if (theTavernHarry in self) {
                      if (self.firstTimeIn) {
                          self.firstTimeIn = false;
                          "^A patron is drinking at the bar and a pretty boy works behind the counter.^
                           ^~Come in, come in,~ the bartender greets you.";
                      }
                      "^A patron is drinking at the bar and a pretty boy works behind the counter.";
                  } else {
                      if (self.firstTimeIn) {
                          self.firstTimeIn = false;
                          "^A pretty boy works behind the counter.^
                           ^~Come in, come in,~ the bartender greets you.";
                      }
                      "^A pretty boy works behind the counter.";
                  }
              }
              self.firstTimeIn = false;
               "^The bartender has left. There's no one behind the counter.";
          ],
          daemon [;
              if (iOldManAnger >= 4) {
                  theTavernNick.tellSorryHarry = false;
                  StopDaemon(self);
              }
              if (iOldManAnger == 3) {
                  iOldManAnger++;
                  move theTavernHarry to outsideJoesBar;
                  StartDaemon(theTavernHarry);

                  theTavernHarry.pissedOff = true;
                  theTavernObj.advanceNick = true;
                  remove outsideJoesBarPerson;
                  remove theTavernDrink;
                  theTavernBooze.&name-->6 = 'drink';
                  theTavernBooze.&name-->7 = 'shot';
                  theTavernBooze.&name-->8 = 'glass';
                  theTavernNick.tellSorryHarry = true;
                  "^~Nick, this one's a jerk. Give 'em not'ing.~
                  ^^With that, the old guy slams down some cash along with his drink and walks out of the bar.";
              }
          ],
          n_to [;
              <<Enter theTavernDoor>>;
          ],
          u_to [;
              if (theTavernStool.sitOn) <<GetOff theTavernStool>>;
              <<Enter theTavernRiser>>;
          ],
          d_to [;
              if (SelfPlayer.onRiser) <<GetOff theTavernRiser>>;
          ],
          cant_go [;
              "You can go north out of the two front doors.";
          ],
          before [;
              Exit:
                  if (theTavernStool.sitOn) <<GetOff theTavernStool>>;
                  if (SelfPlayer.onRiser) <<GetOff theTavernRiser>>;
                  <<Enter theTavernDoor>>;
              Listen:
                  "Heavy metal pumps through the speakers shaking the place a bit. It looks like
                  the bartender likes to turn it up.";
              Smell:
                  "Breathing in, the smell of stale cigarettes and split booze hangs in the air.";
              Sorry:
                  if (theTavernNick in theTavern) <<Answer t_sorry theTavernNick>>;
              Yes:
                  if (theTavernNick in theTavern) <<Answer t_yes theTavernNick>>;
              No:
                  if (theTavernNick in theTavern) <<Answer t_no theTavernNick>>;
              Sleep:
                  return roomSleep();
          ],
          closedUp true,
          firstTime true,
          theTavernEntered false,
          lookFirstTime true,
          firstTimeIn true;

! 6/8/17

  RoomObj -> theTavernObj "room"
    with  name 'area' 'room' 'place' 'tavern',
          description [;
              <<Look theTavern>>;
          ],
          daemon [;
              if (self.advanceNick) {
                  iNickLeave++;
              }
              if (iNickLeave == 10 || iNickLeave == 11) {
                  iNickLeave=15;
                  self.advanceNick = false;
                  remove theTavernNick;
                  remove outsideJoesBarBartender;
                  StartDaemon(theTavernDoor);
                  if (SelfPlayer in theTavern) {
                      if (theTavernNick.askForDrink) {
                          print "^~You know what? Can you give me a minute,~ asks the bartender rubbing his nose, ~I need to ";
                      } else {
                          print "^~Can you give me a minute,~ asks the bartender rubbing his nose, ~I need to ";
                      }
                      iLeaveChoice++;
                      switch (iLeaveChoice) {
                          1: print "go to the bathroom.~";
                          2: print "check on the kitchen. And don't touch anything while I'm gone.~";
                          3: iLeaveChoice=0;
                          print "move the garbage.~";
                      }
                      "^^He steps out of the room.";
                  }
              }
          ],
          before [;
              Search:
                  if (theTavernNick in theTavern) "You'd look a little strange doing that with the bartender here.";
                  if (SelfPlayer.onRiser) "You look around the riser, finding nothing unusual.";
                  if (theTavernStool.sitOn) {
                      theTavernStool.sitOn = false;
                      print "(first getting off the stool)^";
                      "You look around the room, finding nothing unusual.";
                  }
                  "You look around the room, finding nothing unusual.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          advanceNick false;

! 6/8/17

  Object  -> theTavernDoor "front doors"
    with  name 'front' 'door' 'doors' 'frontdoor' 'frontdoors',
          daemon [;
              iNickGone++;
              if (iNickGone >= 10) {
                  move theTavernNick to theTavern;
                  move outsideJoesBarBartender to outsideJoesBar;
                  StopDaemon(self);
                  iNickGone=0;
                  iNickLeave=0;
                  theTavernObj.advanceNick = true;
                  if (SelfPlayer in theTavern) {
                      if (theTavernMarshall.turned) {
                          theTavernMarshall.turned = false;
                          if (vacuumTubeAmp in theTavernMarshall) {
                              theTavernMarshall.turnedFirstTime = true;
                              remove vacuumTubeAmp;
                          }
                          if (SelfPlayer.onRiser) {
                              SelfPlayer.onRiser = false;
                              print "^You step down off the riser, turning the half stack back into place before the bartender gets back.^";
                          }
                      } else {
                          if (SelfPlayer.onRiser) {
                              SelfPlayer.onRiser = false;
                              print "^You step off the stage before the bartender gets back.^";
                          }
                      }
                      if (self.bartenderReturns) {
                          self.bartenderReturns = false;
                          if (theTavernNick.askForDrink) theTavernNick.dontKillAskForDrink = true;
                          theTavernNick.askForDrink = true;
                          "^The bartender walks back into the room, adjusting his collar. ~Can I get you anything?~";
                      }
                      "^The bartender walks back into the room, adjusting his collar. ~Thanks for not messing with anything,
                      gotta love these tunes.~";
                                    }
              }
          ],
          before [;
              Close:
                  "You don't need to do that.";
              Open:
                  "They're already open.";
              Enter, Go:
                  if (theTavernNick in theTavern) {} else {
                      self.bartenderReturns = true;
                  }
                  if (SelfPlayer.onRiser) {
                      SelfPlayer.onRiser = false;
                      if (theTavernMarshall.turned) {
                          theTavernMarshall.turned = false;
                          if (vacuumTubeAmp in theTavernMarshall) {
                              theTavernMarshall.turnedFirstTime = true;
                              remove vacuumTubeAmp;
                          }
                          print "(first turning the half stack into place then stepping down off the riser)^";
                      } else {
                          print "(first stepping down off the riser)^";
                      }
                  }
                  theTavern.firstTimeIn = true;
                  theTavernNick.askForDrink = false;
                  PlayerTo(outsideJoesBar);
                  rtrue;
              Examine, Search:
                  "The front doors to the place are open.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. They're part of the bar.";
          ],
          bartenderReturns false,
    has   concealed static openable ~open pluralname;

! 6/8/17

  OutRch  -> theTavernBooze "bottles"
    with  name 'booze' 'bottle' 'bottles' 'whiskey' 'scotch' 'vodka' 'ph00400' 'ph00401' 'ph00402' 'whisky',
          before [;
              Buy:
                  if (theTavernNick in theTavern) {
                      if (dollarBill in player || dollarBill in clothes)
                          "Since it causes impaired thinking and slows down motor functions,
                          you shouldn't waste your money on that.";
                      if (self.tryToBuy) "~Fork over some cash or stop wasting my time.~";
                      self.tryToBuy = true;
                      "~What? You want to buy this? It's twice as expensive as the stuff over at the alley.
                      You don't look like you can afford it,~ says the bartender.";
                  }
                  "There's no one to sell it.";
              Examine:
                  print "Bottles line the wall behind the ";
                  if (theTavernNick in theTavern) {
                      print "bartender";
                  } else {
                      print "bar";
                  }
                  ". Whiskeys, Scotches, Vodkas. It's a massive selection compared to the bowling alley.";
              Attack, Blow, Burn, Climb, Close, Cut, Dig, Drink, Eat, Empty, Exit, GetOff, JumpOver, Kick, Listen, LookUnder, Open:
                  "You can't do that. It's on the wall behind the bar.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. It's on the wall behind the bar.";
          ],
          tryToBuy false,
     has  pluralname;

! 9/24/17

  Object  -> theTavernCounter "counter"
    with  name 'bar' 'counter' 'far' 'end',
          before [;
              Climb, JumpOver:
                  if (theTavernNick in theTavern) "Are you looking for a fight? The bartender is back there.";
                  "If the bartender caught you behind there, you'd end up in jail.";
              Close:
                  "The counter is already closed. So is the kitchen.";
              Enter, GoBehind:
                  if (theTavernNick in theTavern) "The bartender is running things here.";
                  "If the bartender caught you behind there, you'd end up in jail.";
              Examine, Search:
                  "The bar runs lengthwise along the back of the room. The register's tucked in the corner. At the far end, it opens to the kitchen.";
              Open:
                  if (theTavernNick in theTavern) "Messing with the bar would only upset the bartender.";
                  "It's for employees only back there.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "That doesn't need to go anywhere.";
          ],
    has   concealed static supporter openable ~open;

! 9/24/17

  Object  -> theTavernMarshall "half stack"
    with  name 'marshall' 'half' 'stack' 'cabinet' 'rig' 'amp' 'marshal' 'half-stack' 'back' 'cover',
          before [;
              Close:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (SelfPlayer.onRiser == false) "It's hard to see from here. You need to be up on the riser.";
                  "There is nothing to cover it with.";
              Open:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (junkYardTV.removedVacuumTube) "There's no reason to mess with the Marshall.";
                  if (SelfPlayer.onRiser == false) "It's hard to see from here. You need to be up on the riser.";
                  print "The back cover to the amp is already open";
                  if (self.turned) ".";
                  ". You might want to turn it.";
              Examine:
                  if (self.turned) {
                      print "The half stack is turned at an angle letting you see the row of vacuum tubes in back";
                      if (self.removedVacuumTube) ". One is missing.";
                      ".";
                  }
                  if (SelfPlayer.onRiser) "The Marshall half-stack sits next to you on the riser. Along with an 8-track and mixer, that's stage right.";
                  "The Marshall half-stack sits upon the riser. Inside it must be full of vacuum tubes. Anyone should be able to fix the machine.";
              Switchon:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (SelfPlayer.onRiser == false) "It's hard to see from here. You need to be up on the riser.";
                  "There's no need to do that. You'd only warm up the tubes.";
              Switchoff:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (SelfPlayer.onRiser == false) "It's hard to see from here. You need to be up on the riser.";
                  "That's already off.";
              Take, Remove, PushDir, Pull:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (SelfPlayer.onRiser == false) "It's hard to see from here. You need to be up on the riser.";
                  "You can't just roll it out of here.";
              Push, Turn:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                      if (junkYardTV.removedVacuumTube) "There's no reason to mess with the Marshall.";
                      if (SelfPlayer.onRiser == false) {
                          SelfPlayer.onRiser = true;
                          if (theTavernStool.sitOn) {
                              theTavernStool.sitOn = false;
                              print "(first getting off the stool then stepping upon the riser)^";
                          } else {
                              print "(first stepping upon the riser)^";
                          }
                      }
                      if (self.turned) {
                      self.turned = false;
                      if (vacuumTubeAmp in theTavernMarshall) {
                          theTavernMarshall.turnedFirstTime = true;
                          remove vacuumTubeAmp;
                      }
                      "You turn the amp back into place, making it look like it was never touched.";
                  }
                  self.turned = true;
                  print "You turn the amp quickly. ";
                  if (self.firstTimeTurn) {
                      self.firstTimeTurn = false;
                      print "There are casters on the bottom and the riser is made of polished Maple. ";
                  }
                  if (self.removedVacuumTube) "Looking in the back, you see it's missing a vacuum tube.";
                  if (self.turnedFirstTime) {
                      self.turnedFirstTime = false;
                      move vacuumTubeAmp to self;
                  }
                  "Looking the amp over further, the back of the Marshall is full of vacuum tubes.";
              Search:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  if (junkYardTV.removedVacuumTube) "There's no reason to mess with the Marshall.";
                  if (SelfPlayer.onRiser == false) {
                      SelfPlayer.onRiser = true;
                      if (theTavernStool.sitOn) {
                          theTavernStool.sitOn = false;
                          print "(first getting off the stool then stepping upon the riser)^";
                      } else {
                          print "(first stepping upon the riser)^";
                      }
                  }
                  if (self.turned) {
                  } else {
                      self.turned = true;
                      print "You turn the amp quickly. ";
                      if (self.firstTimeTurn) {
                          self.firstTimeTurn = false;
                          print "There are casters on the bottom and the riser is made of wood. ";
                      }
                      if (self.removedVacuumTube) "But it's missing one of the vacuum tubes.";
                  }
                  if (self.turnedFirstTime) {
                      self.turnedFirstTime = false;
                      move vacuumTubeAmp to self;
                  }
                  if (self.removedVacuumTube) "Looking behind the amp, you see it's missing a vacuum tube.";
                  "Looking behind the amp, you see it's full of vacuum tubes.";
          ],
          turned false,
          turnedFirstTime true,
          firstTimeTurn true,
          removedVacuumTube false,
    has   concealed static container open;

! 9/24/17

  Object  -> theTavernRiser "riser"
    with  name 'riser' 'stage',
          before [;
              Enter, Go, Climb:
                  if (theTavernStool.sitOn) {
                      theTavernStool.sitOn = false;
                      print "(first getting off the stool)^";
                  }
                  if (theTavernNick in theTavern) {
                      "(stepping upon the riser)^
                      ~Don't even think about it,~ the bartender shouts as he sees you move, ~pros only!~";
                  }
                  if (SelfPlayer.onRiser) {
                      "You're already up here.";
                  } else {
                      SelfPlayer.onRiser = true;
                      "You step upon the riser.";
                  }
              Examine, Search:
                  if (SelfPlayer.onRiser)
                      "You have a good view of the bar. Empty as it is. Next to you is the half stack.";
                  "The riser's made from Maple. It's smooth and polished. Two mains sit left and right, but there
                  is no band. The music comes from an 8-track wired into a mixer on the side of the stage.
                  Next to it sits a Marshall half-stack.";
              GetOff:
                  if (SelfPlayer.onRiser) {
                      SelfPlayer.onRiser = false;
                      if (theTavernMarshall.turned) {
                          theTavernMarshall.turned = false;
                          if (vacuumTubeAmp in theTavernMarshall) {
                              theTavernMarshall.turnedFirstTime = true;
                              remove vacuumTubeAmp;
                          }
                          "You push the amp back into place before stepping down off the riser.";
                      } else {
                          "You step down off the riser.";
                      }
                  }
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the bar.";
          ],
    has   concealed static supporter;

! 9/25/17

  Object  -> theTavernMixer "mixer"
    with  name 'mixer' 'controls' 'console',
          before [;
              Examine:
                  "The mixer sits upon the stage, driving the sound that's coming through the speakers.
                  Right now, it's a mix of heavy metal played from an 8-track behind it.";
              Take, Remove, Turn, PushDir, Push, Pull, Switchoff, Switchon, Search:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  "If you touched that it would only bring back the bartender.";
          ],
    has   concealed static;

! 10/11/18

  Object  -> theTavernTapeDeck "tape deck"
    with  name '8-track' 'tape' 'deck' 'cartridge',
          before [;
              Examine:
                  "It's an 8-track tape deck that's wired into the mixer. The cartridge inside plays a
                  tinny mix of heavy metal.";
              Take, Remove, Turn, PushDir, Push, Pull, Switchoff, Switchon, Search:
                  if (theTavernNick in theTavern) "Not with the bartender here.";
                  "If you touched that it would only bring back the bartender.";
          ],
    has   concealed static;

! 9/25/17

  Object  -> theTavernSpeakers "speakers"
    with  name 'main' 'mains' 'speaker' 'speakers',
          before [;
              Examine:
                  "Two main speakers sit on either end of the stage, playing loud heavy metal feed to it by the console.";
              Take, Remove, Turn, PushDir, Push, Pull, Search:
                  if (theTavernNick in theTavern) "With the bartender here, you shouldn't touch them.";
                  "The speakers don't need to go anywhere.";
          ],
    has   concealed static pluralname;

! 9/26/17

  Object  -> theTavernCords "cords"
    with  name 'cord' 'cords' 'xlr' 'cable' 'cables',
          before [;
              Examine:
                  "The XLR cables that run across the stage are used to set up bands that play here. They terminate at the mixer.";
              Take, Remove, Turn, PushDir, Push, Pull, Search:
                  if (theTavernNick in theTavern) "With the bartender here, you shouldn't touch them.";
                  "The cords don't need to go anywhere.";
          ],
    has   concealed static pluralname;

! 5/13/18

  Object  -> theTavernDrink "drink"
    with  name 'drink' 'shot' 'glass',
          before [;
              Buy:
                  "That's the patron's drink. You should leave it alone.";
              Examine, Search:
                  "The old guy sips on his whiskey. A shot glass sits in front of him.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (self.triedToTake) {
                      iOldManAnger++;
                      "The old guy growls at you, darts in his eyes.";
                  }
                  self.triedToTake = true;
                  "~Didn't anybody teach you no manners? Get your own,~ the old guy says, cradling the drink closer.";
          ],
          triedToTake false,
    has   concealed static;

! 5/18/18

  Object  -> theTavernTable "tables"
    with  name 'table' 'tables',
          before [;
              Examine, Search:
                  "Some tables and chairs are scattered in front of the stage. Since there's no band, all of them are empty.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (theTavernNick in theTavern) "~Leave the tables alone. I'm the one that has to put them back.~";
                  "The tables don't need to go anywhere.";
          ],
    has   concealed static pluralname;

! 5/18/18

  Object  -> theTavernStool "stool"
    with  name 'stool' 'stools',
          before [;
              Examine, Search:
                  print "A few stools are in front of the bar";
                  if (self.sitOn) ". You are sitting on one.";
                  if (theTavernHarry in theTavern) ". A patron sits on one of them nursing a shot.";
                  ".";
              Enter:
                  if (self.sitOn) "You're already sitting down.";
                  if (SelfPlayer.onRiser) {
                      SelfPlayer.onRiser = false;
                      if (theTavernMarshall.turned) {
                          theTavernMarshall.turned = false;
                          if (vacuumTubeAmp in theTavernMarshall) {
                              theTavernMarshall.turnedFirstTime = true;
                              remove vacuumTubeAmp;
                          }
                          print "(first turning the half stack into place then stepping down off the riser)^";
                      } else {
                          print "(first stepping down off the riser)^";
                      }
                  }
                  self.sitOn = true;
                  print "You sit down on the stool";
                  if (theTavernHarry in theTavern) " away from the old guy.";
                  ".";
              GetOff:
                  if (self.sitOn) {
                      self.sitOn = false;
                      "Standing up. You get off the stool.";
                  }
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (theTavernNick in theTavern) "~Leave them alone. I gotta deal with 'em, not you.~";
                  "The stools don't need to go anywhere.";
          ],
          sitOn false,
    has   concealed static;

! 5/19/18

  Object  -> theTavernChair "chairs"
    with  name 'chair' 'chairs',
          before [;
              Examine, Search:
                  "Chairs are placed around tables. They're simple in design but comfortable enough.";
              Enter:
                  "Why sit? There's no entertainment.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (theTavernNick in theTavern) "~Don't rearrange the place. Leave the chairs alone.~";
                  "The chairs don't need to go anywhere.";
          ],
    has   concealed static pluralname;

! 11/16/17

  OutRch  -> theTavernKitchen "kitchen"
    with  name 'kitchen',
          before [;
              Examine:
                  "The kitchen sits behind the bar, but the lights are off and nobody is working back there.";
              Enter, Go:
                  if (theTavernNick in theTavern) "With the bartender here, you'd piss him off if you tried that.";
                  "With the bartender back there, you'd only get in trouble.";
          ];

! 01/03/18

  OutRch  -> theTavernRegister "register"
    with  name 'register' 'cash' 'coaster' 'coasters',
          before [;
              Close:
                  if (theTavernNick in theTavern) "~What do you think you're doing?~ growls the bartender.";
                  "That's already closed.";
              Examine:
                  "The register sits in the corner amongst coasters and bottles.";
              Open:
                  if (theTavernNick in theTavern) "~What do you think you're doing?~ growls the bartender.";
                  "The bartender would hear you. There's no telling what he would do.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (theTavernNick in theTavern) "~What do you think you're doing?~ growls the bartender.";
                  "You don't need to do that.";
          ];

! 11/29/18

  Object  -> theTavernVendingMachine "vending machine"
    with  name 'vending' 'machine' 'pack' 'cigarettes' 'cigarette',
          before [;
              Buy:
                  "You need the proper change to buy a pack of cigarettes from the vending machine.";
              Examine:
                  if (self.seenMachine) {
                      self.seenMachine = false;
                      print "You didn't notice it before, but t";
                  } else {
                      print "T";
                  }
                  "here's a vending machine by the bar. It doles out cigarettes at a dollar a pack and takes quarters.";
              Open, Close, Search:
                  if (theTavernNick in theTavern) "~If you're gonna buy a pack. Use it properly.~";
                  "It doesn't work like that.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (theTavernNick in theTavern) "~If you're gonna buy a pack. Use it properly.~";
                  "The vending machine doesn't need to go anywhere.";
          ],
          seenMachine true,
    has   concealed static;

! 12/15/19

  Object  -> theTavernWindow "window"
    with  name 'window',
          before [;
              Examine, Search:
                  "The window looks out onto an empty street.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
              Open, Close:
                  "You don't need to do that.";
          ],
      has concealed static;

  Include "NPC_Nick";

  Include "NPC_Harry";
