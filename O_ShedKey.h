
! ---------------------------------------------------------------------------- !
!       SHED KEY. 02/02/18
!
  Movabl  shedKey
    with  name 'dirt' 'dirty' 'gold' 'key',
          short_name  [;
              if (self.keyCleaned) {
                  print "key"; rtrue;
              }
              print "dirty key"; rtrue;
          ],
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "That would short the whole system out. Who knows where you'd end up when you started the machine.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that. You might need it.";
          ],
          before [;
              Buy:
                  if (self in player) "You already have that.";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Examine, Search:
                  if (self.keyCleaned) "It's a gold-colored key.";
                  "It's a gold-colored key that still has some dirt on it.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "It has an earthy smell to it from being hidden in the dirt.";
              PutOn:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == theTavernMarshall) {
                      if (theTavernNick in theTavern) "The bartender is here. I wouldn't mess with that.";
                      "It doesn't belong there.";
                  }
                  "You don't want to lose that. You might need it.";
              Give:
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      if (self.showAmy) "~What? Do you like me or something? I don't want that.~";
                      "~I don't know what it goes to. I don't want it.~";
                  }
                  if (second == theTavernNick)
                      "~I got my keys. Maybe somebody else lost it.~";
                  if (second == alleyBarPhil) {
                      "~I have my keys,~ he says, shaking his pocket, only to return to the dishes.";
                  }
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~That's worthless. It won't help me with my science project at all. Get out of here.~";
                  }
                  if (second == alleyRentalNancy) "~Is that for your house or something? Like. Creep me out.~";
                  if (second == gasStationJerry) "~Not mine. I got all my keys.~";
                  if (second == theTavernHarry) "~What am I going to do with that?~";
                  if (second == smallParkEddie) "~You trying to implicate me in something. I don't want that.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~Something hidden. Something found. Vut vill you do with vut comes from the ground?~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~"; ! Yes - ~I doubt that.~
                      "~I don't have time for this. Are you going to buy something?~";                 ! No - ~Then leave.~
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Show:
                  if (second == alleyBarPhil) "~Yeah. That's a key. Do you even know what it's for?~";
                  if (second == alleyRentalNancy) "~Not very big. Is it?~";
                  if (second == gasStationJerry) "~Yeah. I didn't lose any of mine,~ the attendant says, checking his pockets.";
                  if (second == theTavernNick) "~Looks like a standard house key. What about it?~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == smallParkEddie) "~Where did you get that?~";    ! Tell Eddie about Shed - ~Hm. Never thought to look under there.~
                  if (second == convenienceStoreKid) {
                      convenienceStore.turningToClerk = true;
                      "~You going to unlock the riddles of the universe with that thing? Good luck.~";
                  }
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~Why show such a thing? It is pointless. You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      self.showAmy = true;
                      "~Is that a key to someone's heart.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I see you like to hold on to junk. But do you have any cash?~";   ! Yes/No for Sarah same as above
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Push, Rub:
                  if (self.keyCleaned) "The key is already clean.";
                  self.keyCleaned = true;
                  self.&name-->0 = 'ph00701';
                  self.&name-->1 = 'ph00702';
                  "You clean the rest of the dirt off the key, practically polishing it.";
              Pet:
                  "You feel nothing unexpected.";
              Remove:
                  <<Take self>>;
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "It lacks the mass to do any damage.";
                  }
              Touch:
                  "It's metal and has warmed up in your hands.";
              Eat:
                  "That would be one way to hide it if you needed to, which you don't.";
              Taste:
                  "Be careful. You don't want to get sick from it.";
          ],
          showAmy false,
          keyCleaned false;
