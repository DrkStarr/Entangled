
! ---------------------------------------------------------------------------- !
!       ART GALLERY. 01/17/18
!
  Room    artGallery "South Street Gallery"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  iRoom++;
                  StartDaemon(backAlley);
                  StartDaemon(artGallerySarah);
              }
              SelfPlayer.outside = false;
              if (self.brokeCat) {
                  backAlley.curatorLeaving = false;
                  backAlley.stillHearGallery = false;
                  backAlley.quickEnterGallery = true;
                  print "Trying to enter the gallery, the curator yells, ~Get out of here before I call the cops.~
                  ^^Not wanting to push it you leave.^";
                  PlayerTo(outsideArtGallery);
                  rtrue;
              }
              print "The gallery looks larger on the inside than out. ";
              if (artGallerySarah.tradedCat) {
                  print "With nothing on the pedestal, the place feels hollow, but the curator seems pleased. ";
              } else {
                  print "There's only one item on display. It's in the center of the room on a pedestal
                  giving the place an open feeling. The piece is clear crystal in the shape of a cat. ";
              }
              print "The smell of incense hangs heavy in the air, and the door out of this place is north.^";
              if (self.firstTimeEnter) {
                  self.firstTimeEnter = false;
                  if (artGallerySarah.seenCatBroken) {
                      "^~Oh look who it is,~ the curator says when she sees you enter her shop.";
                  } else {
                      if (crystalBall in player) {
                          artGallerySarah.seenBallInHands = true;
                          "^The curator sees you enter, smiling to herself, she says, ~that's one hell of a crystal you got there.~";
                      } else {
                          if (self.curatorOutside) {
                             self.curatorOutside = false;
                             print "^The curator steps in from the alley, stopping at the counter and closing the door behind her. ~How are you doing";
                             if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print " this evening";
                             "?~";
                          }
                          print "^The curator stands in the rear of the shop behind a counter. As you walk in, she asks, ~how are you doing";
                          if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) print " this evening";
                          "?~";
                      }
                  }
              }
              "^The gallery is curated by a woman standing behind a counter in the back of the room.";
          ],
          n_to [;
              <<Enter artGalleryDoor>>;
          ],
          w_to [;
              <<Enter artGallerySideDoor>>;
          ],
          cant_go [;
              "You can go north out of the front door.";
          ],
          before [;
              Exit:
                  <<Enter artGalleryDoor>>;
              Listen:
                  if (SelfPlayer.droppedCrystalBall) return PFW();
                  "It's so quiet in here you could hear a pin drop.";
              Smell:
                  "The room has a sickeningly sweet odor that permeates everything.";
              Sorry:
                  <<Answer t_sorry artGallerySarah>>;
              WaveHands:

              Yes:
                  <<Answer t_yes artGallerySarah>>;
              No:
                  <<Answer t_no artGallerySarah>>;
              Sleep:
                  return roomSleep();
          ],
          brokeCat false,
          firstTime true,
          curatorOutside false,
          firstTimeEnter true;

! 01/17/18

  RoomObj -> artGalleryObj "gallery"
    with  name 'room' 'area' 'gallery' 'place',
          description [;
                    <<Look artGallery>>;
          ],
          before [;
              Search:
                  "There's a curator here. You'd look strange searching it.";
                    Take, Remove, Turn, PushDir, Push, Pull:
                              "You can't do that.";
          ];

! 01/17/18

  Object  -> artGalleryDoor "front door"
    with  name 'front' 'door' 'frontdoor' 'tree' 'painting' 'painted' 'symbol' 'root' 'roots' 'intricate',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  if (incense in player)
                      "The curator stops you before you can leave.^
                      ^~Please give me back the incense. It's not for sale.~";
                  artGalleryStatue.pushCat = false;
                  artGallery.firstTimeEnter = true;
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine, Search:
                  "The door has a tree painted on the back of it.
                  Probably, the tree of life by the looks of the curator. It's kept closed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
          ],
          bartenderReturns false,
    has   concealed static openable ~open;

! 01/08/20

  Object  -> artGallerySideDoor "side door"
    with  name 'side' 'door' 'sidedoor',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  if (artGallerySarah.useDoor) artGallerySarah.dontKillUseDoor = true;
                  artGallerySarah.useDoor = true;
                  "~Please use the front door. I use it from time to time, but you have no reason.~";
              Examine, Search:
                  "The side door is on the west wall of the gallery, giving the curator access to the alley.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
          ],
          bartenderReturns false,
    has   concealed static openable ~open;

! 01/17/18

  Object -> artGalleryCounter "counter"
    with  name 'counter' 'desk' 'table',
          before [;
              Enter, GoBehind:
                  if (incense in player) "She pushes you back, ~don't make me get angry.~";
                  "The curator is standing behind it.";
              Examine, Search:
                  print "The curator uses the counter in the back to store paperwork";
                  if (incense in self) {
                      self.seenIncense = true;
                      ". On top of it sits a pack of incense - Nag Champa by the looks of it.";
                  }
                  if (incense in player) ". It sits on the other side of the room.";
                  if (artGallerySarah.moveBlock) ".";
                  if (self.seenIncense) ". The pack of incense now missing.";
                  ". She's standing behind it, watching you.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the gallery.";
          ],
          seenIncense false,
     has  concealed static supporter;

  Object -> artGalleryPaperwork "paperwork"
    with  name 'paperwork' 'paper',
          before [;
              GoBehind:
                  <<Enter artGalleryCounter>>;
              Examine, Search:
                  <<Examine artGalleryCounter>>;
              Take, Remove, Turn, PushDir, Push, Pull:
                  if (incense in player) "~Quit messing around. Hand back the incense.~";
                  "~Get back,~ the curator says, slapping you away.";
          ],
     has  concealed static;

! 01/04/19

  Object -> artGalleryPedestal "pedestal"
    with  name 'pedestal' 'pillar',
          before [;
              Examine, Search:
                  if (artGallerySarah.tradedCat) {
                      "The pedestal is the only thing on display in this room and makes the curator look inept.";
                  } else {
                      "On the top of the pedestal sits a statue. It's the shape of a cat.
                      Perfect in design, it looks flawless as it sits in the center of the room.";
                  }
              Kick:
                  "If you did that, you'd ruin the curator's day.";
              default:
                  return DontTouchCat();
          ],
    has  concealed static supporter;

! 02/03/18

  Object -> -> artGalleryStatue "statue"
    with  name 'clear' 'cat' 'statue' 'crystal',
          before [;
              Buy:
                  "~It takes a lot of work to make something like that. It's not cheap, and I doubt you have the capital to afford it.~";
              Examine, Search:
                  "Clear, and with no cut lines, the crystal statue is a foot
                  tall. The cat has to be molded. It's too perfect.";
              Push, Take, Remove:
                  if (self.pushCat) "~I told you already. Step back. I don't want to have to call the cops.~";
                  self.pushCat = true;
                  artGallerySarah.moveBlock = true;
                  "~What do you think you're doing?~ asks the curator, stepping between you and the cat. ~I don't want to have to call the cops.~";
              default:
                  return DontTouchCat();
          ],
          pushCat false,
     has  concealed static;

  Include "NPC_Sarah";

  [ DontTouchCat;
        iDontTouchCat++;
        switch (iDontTouchCat) {
            1: "~Please, don't touch anything in here.~";
            2: "~As I said, please don't touch anything in here.~";
            3: "~Now you're getting under my skin. Please stop.~";
            4: iDontTouchCat = 0;
               "~Why do you have to be so difficult. Stop.~";
            default:
                "~Please, don't touch anything in here.~";
        }
  ];
