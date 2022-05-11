
! ---------------------------------------------------------------------------- !
!       CHOCOLATE BAR. 01/11/19
!
  Movabl  chocolateBar "chocolate bar"
    with  name 'chocolate' 'bar' 'snack' 'food',
          after [;
              Drop, Insert:
                  move self to player;
                  if (second == gasStationCar) {
                      if (gasStationJerry in gasStation) "Messing with that, you'd get the attention of the attendant.";
                  }
                  if (second == basementTimeMachine || second == basementMetalArm) "It doesn't belong there.";
                  if (second == shedLawnMower) "It doesn't belong there.";
                  if (second == basementGenerator) "It doesn't belong there.";
                  if (second == basementTubes || second == brokenTube) "It doesn't belong there.";
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
                      "You better not. It could melt.";
                  }
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
              Rub:
                  "You don't want to do that. You might melt the chocolate.";
              Examine, Search:
                  "It's a chocolate bar made by Hershey. Even though junk food's not
                                          good for you, it still looks tasty.";
              Give:
                  if (second == smallParkEddie) return GiveChocolateEddie();
                  if (second == gasStationJerry) {
                      "~Are you trying to get on my good side,~ the attendant asks with a hint of hostility,
                      ~I got plenty of candy in here. Why would I want yours?~";
                  }
                  if (second == theTavernHarry) "~What do you think? Am I a kid? I don't eat that crap. I'm drinking here.~";
                  if (second == convenienceStoreAmy) "~Thanks. But I've already had too much tonight.~";
                  if (second == theTavernNick) "~I don't eat that stuff. But thanks anyway.~";
                  if (second == alleyBarPhil) {
                      print "~I don't need that. Not hungry. Smoking here";
                      return PhilWash();
                  }
                  if (second == alleyRentalNancy) "~I don't want any gifts from you. Find someone else to hit on.~";
                  if (second == outsideComplexDoorman) "~I'm not letting you into this place. Don't make me bounce you off your head.~";
                  if (second == madameSorrasMadameSorra) "~Keep your poison to yourself.~";
                  if (second == artGallerySarah)  {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      self.giveToSarah = true;
                      remove self;
                      "~I hope you don't think I'm a pig,~ she says with a smile, taking the chocolate
                      and biting into it. ~I haven't had some in such a long time. I can't stop myself.~^
                      ^In a minute, she finishes the bar in front of you.^
                      ^~Wow. I really should have given that snack to Eddie. Now I feel awful.~";
                  }
                  if (second == junkYardDog) "You should know better than to give chocolate to a dog.";
                  if (second == rustyGateDog) "You should know better than to give chocolate to a dog.";
                  move self to player;
                  if (second == player) rfalse;
                  return TestGiveObject();
              Eat, Open, Taste:
                  if (self.triedToEat) "I thought you were delaying gratification.";
                  self.triedToEat = true;
                  "You think about it, almost grabbing the edge and tearing it open.
                  Chocolate would taste so good right now. But you fight the thought
                  and delay gratification.";
              SmellNoun:
                  if (SmellTest()) rtrue;
                  "There's a hint of chocolate there, but the bar's wrapped up.";
              Close:
                  "The bar is already sealed.";
              Pet, Touch:
                  "The bar is smooth, and you hope it doesn't melt.";
              Pull, PushDir, Push:
                  "You don't need to do that.";
              Show:
                  if (second == smallParkEddie) return GiveChocolateEddie();
                  if (second == alleyBarPhil) "~I take it you like candy?~";
                  if (second == alleyRentalNancy) "~Do you just, like, have a thing for candy?~";
                  if (second == gasStationJerry)
                      "~Yeah, yeah. I got my own,~ he says, popping a piece of candy in his mouth
                      and washing it down with some soda.";
                  if (second == theTavernNick) "~What, are you hungry? I'm not. I can tell you that.~";
                  if (second == theTavernHarry) "~You know what you can do with that? Don't you?~";
                  if (second == madameSorrasMadameSorra) {
                      if (madameSorrasMadameSorra.spiritsRestless) madameSorrasMadameSorra.dontKillSpiritsRestless = true;
                      madameSorrasMadameSorra.spiritsRestless = true;
                      "~Why do you fill yourself with such poison? You make the spirits restless.~";
                  }
                  if (second == convenienceStoreAmy) "~Yeah. I sold it to you. What about it?~";
                  if (second == outsideComplexDoorman) "~Look. Stop wasting our time and move along.~";
                  if (second == artGallerySarah) {
                      if (incense in SelfPlayer) "~I don't want your stuff. I want my incense back.~";
                      "~Look. I love the stuff, but you should give it to Eddie. He's hard up.~";
                  }
                  if (second == junkYardDog) "The dog pays no attention to you.";
                  if (second == rustyGateDog) return ObjectRustyGateDog();
                  if (second == bowlingAlleyBartender || second == bowlingAlleyGirl || second == gravelRoadAttendant) "You can't do that from here.";
              Remove:
                  <<Take self>>;
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                      "There's no reason to throw it away. It might come in handy.";
                  }
          ],
          chocolateScored false,
          giveToSarah false,
          triedToEat false;

  [ GiveChocolateEddie;
        madameSorrasMadameSorra.askForBall = true;
        remove smallParkEddie;
        remove chocolateBar;
        score = score + 5;
        chocolateBar.chocolateScored = true;
        SelfPlayer.gaveEddieDollar = true;
        if (incense in artGalleryCounter) {
            remove incense;
            move babushka to smallPark;
            "He takes the chocolate bar from you.^
            ^~Not much,~ he says, looking at it, ~but it'll do the trick tonight.~
            Tearing open the chocolate, he crams it down his face finishing it in three bites.
            Then he gets up, stretches, and walks out of the park.
            Looking at the bench, you see he was sitting on a scarf that's been left behind.";
        }
        "He takes the chocolate bar from you.^
        ^~Not much,~ he says, looking at it, ~but it'll do the trick tonight.~
        Tearing open the chocolate, he crams it down his face finishing it in three bites.
        Then he gets up, stretches, and walks out of the park.";
  ];
