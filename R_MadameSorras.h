! Madame Sorra will not accept the gift from the PC if they''ve broken the crystal in the gallery.
!
! The gift shall be a babushka, a headscarf, that''s been left behind in the park.
! A bum leaves the scarf behind in the park. He will be there, all day, all night, until .askForBall = true;

! ---------------------------------------------------------------------------- !
!       MADAME SORRAS. 01/04/18
!
  Room    madameSorras "Madame Sorra's"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  if (basement.firstTime) StartDaemon(oldMadameSorra);
              }
              if (self.turnOnDaemon) {
                  self.turnOnDaemon = false;
                  StartDaemon(madameSorrasMadameSorra);
              }
              SelfPlayer.outside = false;

              ! Current Description
              if (basement.firstTime) {
                  if (self.enterFirstTime) {
                      print "The old fortune-teller sits down as you enter the room, slowly seating herself";
                  } else {
                      print "An old fortune-teller sits in the corner of the room";
                  }
                  print (string) random(" behind a crystal ball. She shifts uncomfortably. ",
                  " behind a crystal ball. ",
                  " behind a crystal ball. ",
                  " behind a crystal ball. ");
                  print "The place has little light, ";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print "all";
                  else print "most";
                  print " of it coming from the sign in the window giving off a pink glow.
                  The door out of here is east.^";
                  if (self.enterFirstTime) {
                      self.enterFirstTime = false;
                      print "^";
                      if (self.askedForReading) "~Hello again. How can I help you this evening?~";
                      self.askedForReading = true;
                      oldMadameSorra.askForReading = true;
                      "~Looking to have your palm read this evening?~";
                  }
                  rtrue;
              }

              ! Past Description
              artGallerySarah.playerKnowsSorra = true;
              if (madameSorrasMadameSorra in self) {
                  if (self.enterFirstTime) {
                      if (self.pastEnterFirstTime) {
                          self.pastEnterFirstTime = false;
                          print "The old fortune-teller looks almost spry, carefully seating herself";
                      } else {
                          print "The old fortune-teller sits down as you enter the room, carefully seating herself";
                      }
                  } else {
                      print "An old fortune-teller sits in the corner of the room";
                  }
                  print " behind a crystal ball. ";
              } else {
                  if (crystalBall in self) print "The place is empty, except for the crystal ball left behind. It";
                  else print "The place is empty. It";
              }
              if (madameSorrasMadameSorra in self) {
                  print "The place has little light";
              } else {
                  print " has a little light";
              }
              if (madameSorrasSign.signOn) {
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print ", all";
                  else print ", most";
                  print " of it coming from the sign in the window giving off a pink glow. The door out of here is east.^";
              } else {
                  print " even though the neon sign is off. Darkness tries to settle in. The door out of here is east.^";
              }
              if (self.enterFirstTime) {
                  self.enterFirstTime = false;
                  if (madameSorrasMadameSorra in madameSorras) {
                      print "^";
                      if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) {
                          if (self.askedForReading) "~Hello again, how can I help you this evening?~";
                          self.askedForReading = true;
                          madameSorrasMadameSorra.askForReading = true;
                          "~Looking to have your palm read this evening?~";
                      } else {
                          if (self.askedForReading) "~Hello again, how can I help you?~";
                          self.askedForReading = true;
                          madameSorrasMadameSorra.askForReading = true;
                          "~Looking to have your palm read?~";
                      }
                  }
              }
          ],
          e_to [;
              <<Enter madameSorrasDoor>>;
          ],
          cant_go [;
              "There's no reason to explore the shop. You can go east, out the front door.";
          ],
          before [;
              Exit:
                  <<Enter madameSorrasDoor>>;
              Listen:
                  return PFW();
              Smell:
                  "The faint scent of burning incense can be smelled throughout the room.";
              Sorry:
                  if (oldMadameSorra in madameSorras) <<Answer t_sorry oldMadameSorra>>;
                  if (madameSorrasMadameSorra in madameSorras) <<Answer t_sorry madameSorrasMadameSorra>>;
              Yes:
                  if (oldMadameSorra in madameSorras) <<Answer t_yes oldMadameSorra>>;
                  if (madameSorrasMadameSorra in madameSorras) <<Answer t_yes madameSorrasMadameSorra>>;
              No:
                  if (oldMadameSorra in madameSorras) <<Answer t_no oldMadameSorra>>;
                  if (madameSorrasMadameSorra in madameSorras) <<Answer t_no madameSorrasMadameSorra>>;
              Sleep:
                  return roomSleep();
          ],
          firstTime true,
          enterFirstTime true,
          pastEnterFirstTime true,
          turnOnDaemon false,
          askedForReading false;

! 1/04/18

  RoomObj -> madameSorrasObj "room"
    with  name 'area' 'room' 'place' 'shop',
          description [;
              <<Look madameSorras>>;
          ],
          before [;
              Search:
                  if (oldMadameSorra in madameSorras) "Madame Sorra is here. You'd look strange searching her room.";
                  if (madameSorrasMadameSorra in madameSorras) "Madame Sorra is here. You'd look strange searching her room.";
                  "Looking around, you find nothing out of the ordinary.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ],
          advanceNick false;

! 01/04/18

  Object  -> madameSorrasDoor "door"
    with  name 'front' 'door' 'frontdoor',
          before [;
              Close:
                  "That's already closed.";
              Enter, Go, Open:
                  if (oldMadameSorra in madameSorras) print "You nod goodbye to Madame Sorra before heading out the door.^";
                  if (madameSorrasMadameSorra in madameSorras) print "You nod goodbye to Madame Sorra before heading out the door.^";
                  madameSorras.enterFirstTime = true;
                  PlayerTo(outsideMadameSorras);
                  rtrue;
              Examine, Search:
                  "The front door to the place is closed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the shop.";
          ],
    has   concealed static openable ~open;

! 01/09/18

  Object  -> madameSorrasAfghan "afghan"
    with  name 'afghan' 'blanket' 'shawl',
          before [;
              Examine:
                  "The old woman has it wrapped around her shoulders.";
              Take, Remove, Turn, PushDir, Push, Pull, Search:
                  "~Stay back,~ the old lady says, clenching her hand.";
          ],
    has   concealed static;

! 01/09/18

  Object  -> madameSorrasWindow "window"
    with  name 'window' 'shade' 'ledge',
          before [;
              Burn, Close, Open, Rub:
                  if (oldMadameSorra in madameSorras) print "~Please. Don't touch that.~";
                  if (madameSorrasMadameSorra in madameSorras) "~Please. Don't touch that.~";
                  "You don't need to do that.";
              Examine:
                  print "The window is closed. Shade drawn. ";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) "The only light comes in from the sign.";
                  "But a little sunlight does make it in.";
              Search:
                  "The window's closed. The shade is drawn.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the shop.";
          ],
    has   concealed static openable ~open;

! 05/19/18

  Object  -> madameSorrasSign "sign"
    with  name 'sign' 'neon' 'ph00040' 'ph00041' 'ph00042' 'pink' 'glow' 'light' 'hand' 'print' 'handprint',
          before [;
              Burn, Rub:
                  if (madameSorrasMadameSorra in madameSorras) "~Please. Don't touch that.~";
                  "You don't need to do that.";
              Examine:
                  if (self.signOn) "The pink neon sign is in the shape of a hand. The glow gives off enough light to barely illuminate the room.";
                  "A symbol left behind by the old fortune-teller, the neon sign is in the shape of a hand and has been turned off.";
              Search:
                  "It sits on the ledge of the window.";
              SwitchOn:
                  if (self.signOn) "That's already on.";
                  "You should respect the old lady's wishes.";
              SwitchOff:
                  if (self.signOn) "~Please. Don't touch that.~";
                  "That's already off.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (self.signOn) "~Please. Don't touch that.~";
                  "The sign doesn't need to go anywhere.";
          ],
          signOn true,
    has   concealed static;

  Include "NPC_OldSorra";
