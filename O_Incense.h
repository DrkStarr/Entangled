
! ---------------------------------------------------------------------------- !
!       INCENSE. 01/17/18
!
  Movabl  incense "pack of incense"
    with  name 'incense' 'nag' 'champa' 'stick' 'sticks' 'gonesh' 'pack' 'pac',
          after [;
              Drop:
                  return DropIncense(0);
              Insert:
                  return DropIncense(1);
          ],
          before [;
              Buy:
                  if (self in player) "~I told you it's not for sale. Please put it back.~";
                  "~It's not for sale. Sorry.~";
              Insert:
                  if (second == clothes) {
                      move self to player;
                      "You better put that back.";
                  }
              Examine, Search:
                  if (self in artGalleryCounter) "A pack of incense sits on the counter. It must be the source of the smell in the place.";
                  "The pack of Gonesh sticks is golden with black lettering that reads, Nag Champa.";
              PutOn:
                  if (self in player) {
                      if (second == artGalleryCounter) return DropIncense(1);
                      "~Stop messing around and give back my incense.~";
                  } else {
                      if (second == artGalleryCounter) {
                          rfalse;
                      }
                  }
              Read:
                  if (self in artGalleryCounter) "From here, it looks like it says, Nag Champa.";
                  "It says Gonesh Sticks, Nag Champa.";
              Give:
                  if (second == artGallerySarah) return DropIncense(2);
              Rub, Touch:
                  "~Don't play with that. Just give me back my incense.~";
              Show:
                  if (second == player) rfalse;
                  "~Come on now. What are you? A child? Give it back.~";
              SmellNoun:
                  if (self in player) "Definitely the source of the room's odor.";
                  "You're not holding on to that.";
              Take, Remove:
                  if (self in player) "You already have that.";
                  return TakeIncense(0);
              PushDir, Push, Turn:
                  if (self in player) "You don't need to do that.";
                  return TakeIncense(1);
              Pull:
                  if (self in player) "You don't need to do that.";
                  return TakeIncense(2);
              Pet:
                  "You feel nothing unexpected.";
              ThrowAt:
                  if (self in player) {
                      if (second == artGalleryStatue) "You would break the statue and ruin the curator's day.";
                  }
              Eat, Taste:
                  "That's not what it's used for. The taste would be awful.";
              Open:
                  if (self in player) "~Why are you messing around? Give it back.~";
                  if (self.tiredToOpen) "The curator sees you eyeing it, ~Please don't even look at it. It's not for sale.~";
                  self.tiredToOpen = true;
                  "The curator sees you eyeing it, ~Please don't mess with the incense. It's not for sale.~";
              Close:
                  if (self in player) "~Don't mess with it. Give it back.~";
                  if (self.tiredToOpen) "The curator sees you eyeing it, ~Please don't even look at it. It's not for sale.~";
                  self.tiredToOpen = true;
                  "The curator sees you eyeing it, ~Please don't mess with the incense. It's not for sale.~";
          ],
          tiredToOpen false,
    has   concealed;

  [ TakeIncense iPass;
        move incense to player;
        switch (iPass) {
            0: print "The curator tries to stop you, just missing your arm.^^";
            1: print "You push the incense off the counter. The curator tries to stop you, but you pick it up first.^^";
            2: print "You pull on the incense, so it falls off the counter. The curator tries to stop you, but you pick it up first.^^";
        }
        "~What are you doing? Put back my incense. It's not for sale.~";
  ];

  [ DropIncense iPass;
        switch (iPass) {
            0: print "Dropping the incense to the ground, thin sticks of scented wood go flying across the room.^";
            1: print "Trying to put it back, the curator yanks it out of your hand. Thin sticks of scented wood go flying across the room.^";
            2: print "Giving the curator the incense back, she yanks it out of your hand. Thin sticks of scented wood go flying across the room.^";
        }
        remove incense;
        artGallery.brokeCat = true;
        backAlley.curatorLeaving = true;
        backAlleyDumpster.catInDumpster = true;
        move backAlleyShards to backAlleyDumpster;
        print "^~Look at what you did,~ she says, bending over to pick them up. But she slips on one bumping into the crystal cat. Before it hits the ground, you slip out the door.^";
        PlayerTo(outsideArtGallery);
        rtrue;
  ];
