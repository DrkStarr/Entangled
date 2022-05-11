! Player has to look at shelf/junk food, seeing that it's out of snack bars
! Then the player has to talk to the attendant about the snack bars
! The attendant will have to go in the back and get some more snack bars
! Then the player will be able to steal the beef jerky

! If you make the attendant your friend, they'll give away the beef jerky when asked about it
!
! Can ask about snake bars, junk food, beef jerky, and cold drinks.
!
!
! Ask Amy about Coke = Cola / Pop = Soda
! Buy Snacks - Needs to say that there are none.


! When the player gets rid of the kid, the clerk says, "Whew, that was crazy. Thanks."

! ---------------------------------------------------------------------------- !
!       CONVENIENCE STORE. 09/28/17
!
  Room    convenienceStore "Convenience Store"
    with  description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
              }
              if (basement.firstTime && self.daemonTriggerOldAmy) {
                  self.daemonTriggerOldAmy = false;
                  StartDaemon(convenienceStoreOldAmy);
              }
              if (basement.firstTime == false && self.daemonTriggerAmy) {
                  self.daemonTriggerAmy = false;
                  StartDaemon(convenienceStoreAmy);
                  if (convenienceStoreKid in self) StartDaemon(self);
              }
              SelfPlayer.outside = false;
              if (basement.firstTime) {
                  print "The entrance to the store is clean except for scuff marks on the floor.
                  Rows of junk food line the place, and there's a cooler in back for the cold drinks.
                  The door out of this place is west";
                  if (self.walkIn) {
                      self.walkIn = false;
                      if (convenienceStoreOldAmy in self) print ".^^Amy looks up from her paperback. Seeing you enter the store, she nods going back to her book";
                  } else {
                      if (convenienceStoreOldAmy.lookUp) {
                      } else {
                          if (convenienceStoreOldAmy in self) {
                              print ".^^Amy reads her paperback while sitting behind the counter";
                          }
                      }
                  }
                  ".";
              } else {
                  if (convenienceStoreKid in convenienceStore)
                      "Dirt and scuff marks cover the entrance to the store. Rows of junk food line the place,
                      but there's a pharmacy in back where the cooler for the cold drinks usually is.
                      Packs of beef jerky are displayed next to the register. The door out of this place is west,
                      next to it is a book rack.^
                      ^At the register is a kid trying to persuade the clerk out of a comic.";
                  print "Dirt and scuff marks cover the entrance to the store. Rows of junk food line the place,
                  but there's a pharmacy in back where the cooler for the cold drinks usually is.
                  Packs of beef jerky are displayed next to the register. The door out of this place is west,
                  next to it is a book rack";
                  if (self.walkIn) {
                      self.walkIn = false;
                      if (convenienceStoreAmy in self) print ".^^A clerk looks up from a comic book. Seeing you enter the store, she nods going back to the comic";
                  } else {
                      if (convenienceStoreAmy.lookUp) {
                      !   if (convenienceStoreAmy in self) print ".^^A clerk watches you from behind the counter";
                      } else {
                          if (convenienceStoreAmy in self) print ".^^A clerk reads a comic book sitting behind the counter";
                      }
                  }
                  ".";
              }
              ".";
          ],
          w_to [;
              <<Enter convenienceStoreDoor>>;
          ],
          cant_go [;
              "You can head out the store to the west.";
          ],
          before [;
              Exit:
                  <<Enter convenienceStoreDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  if (convenienceStoreKid in convenienceStore) {
                      switch (kidTest) {
                          1,3,5,7,10:
                              "The clerk trys to reason with the kid.";
                          12:
                              "The clerk thinks for a minute.";
                          default:
                              "The kid continues.";
                      }
                  }
                  if (convenienceStoreOldAmy in self || convenienceStoreAmy in self)
                      "It's quiet in here, except for the clerk that turns a page now and then.";
                  "You hear the clerk rummaging in the back.";
              Smell:
                  "The store smells clean. Disinfectant lingers strong in the air.";
              Sorry:
                  if (convenienceStoreKid in convenienceStore) <<Answer t_sorry convenienceStoreKid>>;
                  if (convenienceStoreAmy in convenienceStore) <<Answer t_sorry convenienceStoreAmy>>;
                  if (convenienceStoreOldAmy in convenienceStore) <<Answer t_sorry convenienceStoreOldAmy>>;
              Wave:

              Yes:
                  if (convenienceStoreKid in convenienceStore) <<Answer t_yes convenienceStoreKid>>;
                  if (convenienceStoreAmy in convenienceStore) <<Answer t_yes convenienceStoreAmy>>;
                  if (convenienceStoreOldAmy in convenienceStore) <<Answer t_yes convenienceStoreOldAmy>>;
              No:
                  if (convenienceStoreKid in convenienceStore) <<Answer t_no convenienceStoreKid>>;
                  if (convenienceStoreAmy in convenienceStore) <<Answer t_no convenienceStoreAmy>>;
                  if (convenienceStoreOldAmy in convenienceStore) <<Answer t_no convenienceStoreOldAmy>>;
              Sleep:
                  return roomSleep();
          ],
          daemon [;
              if (kidTest > 13) kidTest = 9;
              if (player in self) {
                  kidTest++;
                  if (self.turningToClerk) {
                      switch (kidTest) {
                          2,4,6,8,11,13:
                              print "^";
                          default:
                              print "^Turning to the clerk, he says, ";
                      }
                  } else {
                      print "^";
                  }
                  switch (kidTest) {
                      1: "~Look, I know you let me read them, but can't you just give me one?~ the kid whines.";
                      2: self.turningToClerk = false;
                         "~Mel, I told you a thousand times, I can't give them away for free,~ says the clerk.";
                      3: if (self.turningToClerk) {
                             self.turningToClerk = false;
                             "~But what about the one you're reading? You could give me that.~";
                         } else {
                             "~But what about the one you're reading? You could give me that,~ says the kid.";
                         }
                      4: self.turningToClerk = false;
                         "~No way. All of those are mine,~ shouts the clerk, ~I bought them. Wonder Woman is going to be worth something one day.~";
                      5: self.turningToClerk = false;
                         "~You're right, but I'm working on a new science project. I'd love to use some of the art.~";
                      6: self.turningToClerk = false;
                         "~Don't even start with that. I've seen your projects.~";
                      7: self.turningToClerk = false;
                         "~That's not fair. I put a lot of work into those things. You wait. Someday I'll get one to work.~";
                      8: self.turningToClerk = false;
                         "~Like you'll get a comic out of me?~ says the clerk, laughing to herself.";
                      9: if (self.turningToClerk) {
                             self.turningToClerk = false;
                             "~Ha. Ha. Very funny.~";
                         } else {
                             "~Ha. Ha. Very funny,~ the kid says without smiling.";
                         }
                     10: if (self.turningToClerk) {
                             self.turningToClerk = false;
                             "~Come on. Let me take one home with me. I'll even bring it back.~";
                         } else {
                             "~Come on. Let me take one home with me. I'll even bring it back,~ says the kid.";
                         }
                     11: self.turningToClerk = false;
                         "~I doubt that. Plus, we couldn't sell it afterward. Come on. I have another customer,~ the clerk reasons.";
                     12: self.turningToClerk = false;
                         "~I don't care about them.~ The kid snorts to himself, ~It's only one.~";
                     13: kidTest = 9;
                         self.turningToClerk = false;
                         "~Hmm,~ the clerk grunts to herself.";
                  }
              }
          ],
          walkIn false,
          daemonTriggerAmy true,
          daemonTriggerOldAmy true,
          firstTime true,
          turningToClerk false;

! 09/28/17

  RoomObj -> convenienceStoreObj "store"
    with  name 'convenience' 'store' 'area' 'room' 'dirt' 'scuff' 'marks' 'place',
          description [;
              <<Look convenienceStore>>;
          ],
          before [;
              Rub:
                  "That's not your job.";
              Search:
                  "The store needs mopping. The floor's scuffed and dirty.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 09/28/17

  Object  -> convenienceStoreDoor "door"
    with  name 'door' 'doors' 'entrance',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  if (basement.firstTime) {
                      convenienceStoreOldAmy.lookUp = false;
                  } else {
                      if (convenienceStoreAmy in convenienceStore) {} else {
                          move convenienceStoreAmy to convenienceStore;
                          convenienceStoreAmy.amyReturn = true;
                      }
                      convenienceStoreAmy.lookUp = false;
                  }
                  iAmyLookUp = 0;
                  kidTest = 42;
                  convenienceStore.walkIn = true;
                  PlayerTo(outsideStore);
                  rtrue;
              Examine, Search:
                  "Stickers and ads cover the door.";
              Read:
                  <<Read convenienceStoreAds>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the store.";
          ],
     has  concealed static;

! 09/29/17

  Object  -> convenienceStoreShelf "shelf"
    with  name 'shelf' 'row' 'rows',
          before [;
              Examine, Search:
                  if (basement.firstTime == false) {
                      if (convenienceStoreAmy.amyReturn) "The row is full of snack bars with a wide selection of assorted chocolate.";
                      convenienceStoreAmy.seensnacks = true;
                      "Looking down the row, you see it's missing a box of Snickers bars.";
                  }
                  "The row is full of snack bars with a wide selection of assorted chocolate.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The shelf doesn't need to go anywhere.";
          ],
     has  concealed static;

! 09/29/17

  Object  -> convenienceStoreFood "food"
    with  name 'box' 'snack' 'bar' 'junk' 'food' 'chocolate' 'candy' 'snicker',
          before [;
              Buy, Take, Remove:
                  "It's all junk. You don't need any of it.";
              Examine, Search:
                  <<Examine convenienceStoreShelf>>;
              Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
          ],
     has  concealed static;

! 09/29/17

  Object  -> convenienceStoreSnacks "snacks"
    with  name 'snacks' 'bars' 'snickers',
          before [;
              Buy, Take, Remove:
                  "It's all junk. You don't need any of it.";
              Examine, Search:
                  <<Examine convenienceStoreShelf>>;
              Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
          ],
     has  concealed static pluralname;

! 02/03/20

  Object  -> convenienceStoreCounter "counter"
    with  name 'counter',
          before [;
              Examine:
                  if (basement.firstTime) "The register sits on the counter with the clerk behind it.";
                  "On the counter are packs of beef jerky that sit in front of the register.";
              Enter:
                  if (basement.firstTime || convenienceStoreAmy in convenienceStore) "It would be strange if you jumped up there, plus it would upset the clerk.";
                  "It would be strange if you jumped up there, and the clerk would be upset when she got back.";
              JumpOver:
                  if (basement.firstTime || convenienceStoreAmy in convenienceStore) "The clerk is back there, and that would cause all sorts of problems.";
                  "That would cause all sorts of problems.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "The counter doesn't need to go anywhere.";
          ],
     has  concealed static supporter;

! 01/02/18

  Object  -> convenienceStoreRegister "register"
    with  name 'register',
          before [;
              Close:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Stay back,~ the clerk says, slapping at your hand.";
                  if (convenienceStoreOldAmy in convenienceStore) "~Stay back,~ the clerk says, slapping at your hand.";
                  "That's already closed.";
              Examine, Search:
                  if (basement.firstTime) "The register sits on the counter with the clerk behind it.";
                  "The register sits up on the counter with packs of beef jerky placed next to it to tempt customers.";
              Open:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Stay back,~ the clerk says, slapping at your hand.";
                  if (convenienceStoreOldAmy in convenienceStore) {
                      convenienceStoreOldAmy.lookUp = true;
                      "The clerk moves swiftly. ~Stay back,~ she says, slapping at your hand.";
                  }
                  "The clerk would hear you and come back for sure.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Stay back,~ the clerk says, slapping at your hand.";
                  if (convenienceStoreOldAmy in convenienceStore) "~Stay back,~ the clerk says, slapping at your hand.";
                  "The register doesn't need to go anywhere.";
          ],
     has  concealed static;

! 05/22/18

  Object  -> convenienceStoreAds "ads"
    with  name 'ad' 'ads' 'cigarette' 'cigarettes' 'cig' 'cigs' 'fag' 'stickers',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (basement.firstTime) {
                      "~Sorry. We stopped selling cigarettes. Everybody's trying to go healthy.~";
                  }
                  if (convenienceStoreAmy in convenienceStore) "~Sorry. I'm not old enough to sell those. You'll have to wait for the owner to get back.~";
                  "There's no one to sell you that.";
              Examine, Search:
                  "The door's covered in colorful ads. All of them for beer or cigarettes.";
              Take:
                  "The ads are glued to the door. They'd be hard to scrape off.";
              Read:
                  if (basement.firstTime) "The beers are going for $5.79 a six-pack. Cigarettes only advertise brands.";
                  "The beers are going for $3.49 a six-pack. Cigarettes only advertise brands.";
          ],
          tryToBuy false,
    has   concealed static pluralname;

! 10/07/19

  Object  -> convenienceStoreBeer "beer"
    with  name 'beer',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (basement.firstTime) {
                      if (convenienceStoreOldAmy.askAboutCooler) {
                          TestLookingUp();
                          "~Sorry. Like I was saying. We were bought out.~";
                      }
                      TestLookingUp();
                      convenienceStoreOldAmy.askAboutCooler = true;
                      "~Sorry. There's none. A couple of college kids cleaned us out.~";
                  }
                  if (convenienceStoreAmy in convenienceStore) "~Sorry. I'm not old enough to sell that. You'll have to wait for the owner to get back.~";
                  "There's no one to sell you that.";
              Examine, Search:
                  if (basement.firstTime) "Usually, it's kept in the cooler. But there are none. It looks like they're sold out.";
                  "Six-packs are piled high in the cooler, filling the small container.";
              Read:
                  <<Read convenienceStoreAds>>;
              Take:
                  if (basement.firstTime) "There are none. They're sold out.";
                  if (convenienceStoreAmy in convenienceStore) "There are plenty of beers. If only the clerk would sell you one.";
                  "No one's here, but that's no way to solve your problems.";
          ],
    has   concealed static;

! 06/28/19 - 1 YEAR 3 MONTHS UNTIL RELEASE

  OutRch  -> convenienceStoreCoke "coke"
    with  name 'coke' 'cokes' 'soda' 'drink' 'drinks',
          before [;
              Buy, Take:
                  if (basement.firstTime) "As good as one would taste, you don't need it and can't afford it.";
                  "There are no Cokes. The place only has beer in the cooler.";
              Examine, Search:
                  if (basement.firstTime) "The drinks are kept in a cooler in the back. There are a few Cokes left.";
                  "There are no Cokes. The place only has beer in the cooler.";
              Open, Close, Enter, Go:
                  if (basement.firstTime) "The cooler is in the back, but you don't need a drink even though one might taste good.";
                  "There are no Cokes. The place only has beer in the cooler.";
          ],
    has   concealed static;

! 06/19/20

  OutRch  -> convenienceStoreCooler "cooler"
    with  name 'cooler',
          before [;
                Examine, Search:
                    if (basement.firstTime) "Drinks are kept in a cooler in the back. There are a few Cokes left. The beer is sold out.";
                    print "The cooler in the back is small";
                    if (self.lookAtCooler) {
                        self.lookAtCooler = false;
                        print "er than what you are used to seeing";
                    }
                    " and packed full of beer.";
                Enter, Go:
                    print "Sorry. You're not going to find some sort of magic portal. ";
                    if (basement.firstTime) "You are too big to fit in there.";
                    "And it's full of beer.";
                Open, Close:
                    if (basement.firstTime) "The cooler is in the back, but you don't need a drink even though one might taste good.";
                    if (convenienceStoreAmy in convenienceStore) "The place only has beer. Too bad the clerk won't sell you any.";
                    "No one's here, but that's no way to solve your problems.";
                Take:
                    "That doesn't need to go anywhere.";
          ],
          lookAtCooler true,
    has   concealed static;

! 06/27/19

  Object  -> convenienceStoreNoteBook "paperback"
    with  name 'paperback' 'book' 'paper' 'page',
          before [;
              Examine, Search:
                  if (convenienceStoreOldAmy.lookUp) "The paperback sits in the clerk's lap. Clicking her nails, she itches to get back to reading.";
                  "It's a worn copy of On The Road. The clerk reads it with tired eyes.";
              Read:
                  "You try to look over the counter, but the clerk leans back.";
              Take, Remove:
                  if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
                  convenienceStoreOldAmy.lookUp = true;
                  "~What are you doing?~ the clerk asks, pulling away from you, ~can't you see I'm reading.~";
              default:
                  "I don't think the clerk would care for that.";
          ],
    has   concealed static;

Include "NPC_OldAmy";

! 09/29/17

  Object  convenienceStoreJerky "display"
    with  name 'pack' 'packs' 'package' 'sealed' 'stick' 'sticks' 'beef' 'jerky' 'plastic' 'meat' 'display',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (convenienceStoreAmy in convenienceStore) "~I'd love to sell you some, they come six in a pack and cost $1.50.~";
                  <<Take self>>;
              Examine:
                  "There are packs of beef jerky displayed at the register, enticing people to buy.";
              Search:
                  "You can't. They're sealed in plastic.";
              Take, Remove:
                  if (convenienceStoreAmy in convenienceStore) "Not with the clerk here.";
                  if (self.jerkyTaken) "You don't need any more of the jerky.";
                  self.jerkyTaken = true;
                  move beefJerky to player;
                  "You take one of the sealed beef packs. No one will notice.";
              Turn, PushDir, Push, Pull:
                  "You don't need to do that.";
          ],
          jerkyTaken false,
     has  concealed static;

! 05/16/18

  Object  convenienceStorePharmacy "pharmacy"
    with  name 'pharmacy',
          before [;
              Examine, Search:
                  "It looks like the pharmacy is open. The lights are on, but no one is working back there.";
              Enter, Go:
                  "There's no reason to go back there.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
     has  concealed static;

! 10/18/18
! 'clerk?s' for Spatterlight

  Object  convenienceStoreClerksComic "clerk's comic"
    with  name 'clerk^s' 'clerk?s' 'clerks' 'comic' 'book',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (convenienceStoreAmy in convenienceStore) {
                      if (self.tryToBuyComic) "~Sorry. I'm not parting with any of them.~";
                      self.tryToBuyComic = true;
                      "~I'm not going to sell you this one, and I'm collecting all those.~";
                  }
                  "That's the clerk's comic. It's not for sale.";
              Examine, Search:
                  if (convenienceStoreKid in convenienceStore)
                      "The comic sits in the clerk's lap. She's holding on to it so hard her nails are starting to dig into it.";
                  if (convenienceStoreAmy in convenienceStore) "The clerk is reading Wonder Woman #272. It's the current issue that's out.";
                  "The clerk left the comic behind when she went in the back.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Get your hands off. It's mine. I paid for it.~";
                  if (beefJerky in player) "Haven't you taken enough already?";
                  "Maybe you shouldn't steal that.";
          ],
          tryToBuyComic false,
    has   concealed static;

! 10/18/18

  Object  convenienceStoreComicBookRack "wired rack"
    with  name 'ph000111' 'wired' 'rack',
          before [;
              Examine, Search:
                  "It's the circular kind of wired rack that holds a number of comics.";
              Turn:
                  "You spin the rack a bit, but there are no other comics. It's filled with Conan, Wonder Woman, and X-Men.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Please. Leave the rack alone.~";
                  "The comic book rack doesn't need to go anywhere.";
          ],
    has   concealed static;

! 10/18/18

  Object  convenienceStoreConanComic "Conan comic"
    with  name 'conan' 'comic' 'comics' 'book' 'books' '115',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (convenienceStoreAmy in convenienceStore) {
                      if (convenienceStoreAmy.askAboutComic) convenienceStoreAmy.dontKillAskAboutComic = true;
                      convenienceStoreAmy.askAboutComic = true;
                      "~Are you going to buy it? You know that's a special 10th-anniversary edition. It's seventy-five cents.~";
                  }
                  "The clerk left and can't sell you that right now.";
              Examine, Search:
                  "It's Conan The Barbarian #115, the 10th-anniversary edition. Conan attacks in the center of the
                  cover, drawn on top of a yellow background that has green reliefs of Conan attacking different
                  enemies over the years.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Look. Don't go leafing through it. Buy it or move on.~";
                  if (beefJerky in player) "Haven't you taken enough already?";
                  "Maybe you shouldn't steal that.";
          ],
    has   concealed static;

! 10/18/18

  Object  convenienceStoreWonderWomanComic "Wonder Woman comic"
    with  name 'wonder' 'woman' 'comic' 'comics' 'book' 'books' 'current' 'issue' '272',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (convenienceStoreAmy in convenienceStore) {
                      if (self.tryToBuyWW) "~Sorry. I'm not parting with any of them.~";
                      self.tryToBuyWW = true;
                      "~Ah. I'd love to sell you one, but I'm collecting 'em. All those are mine.~";
                  }
                  "The clerk left and can't sell you that right now.";
              Examine, Search:
                  "It's Wonder Woman #272. There's a drawing of Wonder Woman standing against a yellow background
                  and the American flag. She's smiling with a bald eagle on her arm.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Don't go leafing through those. They're mine.~";
                  if (beefJerky in player) "Haven't you taken enough already?";
                  "Maybe you shouldn't steal that.";
          ],
          tryToBuyWW false,
    has   concealed static;

! 10/18/18

  Object  convenienceStoreXMenComic "X-Men comic"
    with  name 'x-men' 'xmen' 'comic' 'comics' 'book' 'books' '138',
          before [;
              Buy:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (convenienceStoreAmy in convenienceStore) {
                      if (dollarBill in player) "~That's not Stan Lee's best work. I wish we had Spiderman in, but the boss won't splurge. Don't waste your money.~";
                      if (convenienceStoreAmy.askAboutXMenComic) convenienceStoreAmy.dontKillAskAboutXMenComic = true;
                      convenienceStoreAmy.askAboutXMenComic = true;
                      "~Are you really going to buy it? That's not Stan Lee's best. It's also fifty cents.~";
                  }
                  "The clerk left and can't sell you that right now.";
              Examine, Search:
                  "It's X-Men #138. One of the X-Men walks away from the group huddled in the background.
                  The words ~Exit Cyclops!~ in green at the bottom.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (convenienceStoreKid in convenienceStore) "~Get back. I'm dealing with this kid, and I don't need you messing around.~";
                  if (convenienceStoreAmy in convenienceStore) "~Look. Don't go leafing through it. Buy it or move on.~";
                  if (beefJerky in player) "Haven't you taken enough already?";
                  "Maybe you shouldn't steal that.";
          ],
    has   concealed static;


! 08/24/20

  ORchMel convenienceStoreMelGone "kid"
    with  name 'kid' 'boy' 'child' 'mel' 'tween',
          before [;
              Examine:
                  "You can't see him anymore.";
              Follow:
                  outsideStore.followKid = true;
                  <<Enter convenienceStoreDoor>>;
          ],
          life [;
              "You can't see him anymore.";
          ],
          orders [;
              "You can't see him anymore.";
          ],
     has  animate male scenery;

! 10/18/18

!  Object  convenienceStoreUnknownComic "The Unknown Soldier comic"
!    with  name 'unknown' 'soldier' 'comic' 'comics' 'book' 'books',
!          before [;
!              Buy:
!                  if (convenienceStoreAmy in convenienceStore) {
!                      if (dollarBill in player) "~Nobody buys The Unknown Soldier anymore. Don't encourage 'em to make more.~";
!                      "~Are you really going to buy it? It's fifty cents, you know.~";
!                  }
!                  "The clerk left and can't sell you that right now.";
!              Examine, Search:
!                  "It's The Unknown Soldier #244. Two submarines face off on the cover with the unknown
!                  soldier stopping a torpedo. The caption reads: ~The Sub That Would Not Die!~";
!              Take, Remove, Turn, PushDir, Push, Pull:
!                  if (convenienceStoreAmy in convenienceStore) "~Look. Don't go leafing through it. Buy it or move on.~";
!                  if (beefJerky in player) "Haven't you taken enough already?";
!                  "Maybe you shouldn't steal that.";
!          ],
!    has   concealed static proper;
