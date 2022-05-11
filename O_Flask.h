
! ---------------------------------------------------------------------------- !
!       FLASK. 05/10/18
!
  Movabl  flask "flask"
    with  name 'flask' 'top' 'aluminum' 'alcohol' 'booze' 'drink',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
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
              Close, Turn:
                  "The top is already screwed down.";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better hold on to that.";
                  }
              Rub:
                  "You already did your best. Your hands are going to stink for a week.";
              Drink:
                  "That's no way to solve your problems.";
              Empty:
                  "I think they call that alcohol abuse.";
              Examine, Search:
                  "It's a metal flask that feels like it has a bit of liquor left behind.";
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
                  if (second == smallParkEddie) return GiveFlaskEddie();
                  if (second == gasStationJerry) {
                      if (self.jerryDone) "You should leave him alone about that.";
                      if (self.showToJerry) {
                          self.jerryDone = true;
                          "You egg him on a bit.^
                          ^~It's more than that. I'm working here and don't want to blow it.
                          Find someone else to drink with.~";
                      }
                      self.showToJerry = true;
                      "~I'm sorry,~ the attendant says sheepishly, ~I can't drink. Not old enough.~";
                  }
                  if (second == theTavernHarry) "~You trying to get on my good side? Can't you see I have my own,~ he says, nodding to his drink.";
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~I can't take that. I'm too young to drink.~";
                  }
                  if (second == convenienceStoreKid) "You know better than that. He's too young to drink.";
                      if (second == theTavernNick) "~You know. It usually works the other way 'round. I serve the drinks.~";
                      if (second == alleyBarPhil) {
                      print "~Don't let anybody see you with that in here. I'd get in trouble";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~I wouldn't have a drink with you if you paid me.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~So. You like to drink. You're no better than that snake.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~I'm not that type of lady. I won't drink with just anyone.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Open:
                  "Are you looking for a drink? That's no way to solve your problems.";
              Pull, PushDir, Push:
                  "You don't need to do that.";
              Show:
                  if (second == smallParkEddie) return GiveFlaskEddie();
                  if (second == convenienceStoreKid) "You know better than that. He's too young to drink.";
                  if (second == alleyBarPhil) "~Keep it down. I don't want anybody else to see that.~";
                  if (second == alleyRentalNancy) "~Looking to get tipsy. Do it alone.~";
                  if (second == gasStationJerry) "~No thanks.~";
                  if (second == theTavernNick) "~Get out of here with that. We serve our own.~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == madameSorrasMadameSorra) {
                      "~I do not partake in poison. It clouds the mind.~";
                  }
                  if (second == convenienceStoreAmy) {
                      if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                      "~Maybe if I was older, but I can't.~";
                  }
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      if (self.showToSarah) "~As I was saying, please don't give that to Eddie. It's slowly killing him.~";
                      self.showToSarah = true;
                      "~Oh no. What are you going to do with that? Whatever it is, please don't give it to Eddie. I've been trying to get him to quit.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == convenienceStoreMelGone) "You can't see him anymore.";
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              SmellNoun:
                  if (player in basement)
                      "The overpowering smell of burnt hair and cooked meat pervades the room.";
                  "The stench of rot and grease comes from your hands since you reached into the dumpster. It's overpowering.";
              Pet:
                  "You feel nothing unexpected.";
              ThrowAt:
                  if (self in player) {
                      if (second == parkingLotNeonSign) "What do you want to do? Break it before anybody else?";
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "You might need that. Better hold onto it.";
                  }
              Touch:
                  "You weigh it in your hand. Heavier than its size, the liquid sloshes around inside.";
              Remove:
                  <<Take self>>;
              Eat, Taste:
                  "Thinking about chewing on a bit of aluminum? You'd break your teeth.";
          ],
          showToSarah false,
          showToJerry false,
          jerryDone false;

  [ GiveFlaskEddie;
        madameSorrasMadameSorra.askForBall = true;
        smallParkEddie.gaveBumFlask = true;
        remove smallParkEddie;
        remove flask;
        if (incense in artGalleryCounter) {
            remove incense;
            move babushka to smallPark;
            "He takes the flask from you.^
            ^~You know. I was going to give this stuff up. But why bother? Am I right?~
            Downing the last swig, he gets up, stretches, and walks out of the park.
            Looking at the bench, you see he was sitting on a scarf.";
        }
        "He takes the flask from you.^
        ^~You know. I was going to give this stuff up. But why bother? Am I right?~
        Downing the last swig, he gets up, stretches, and walks out of the park.";
  ];
