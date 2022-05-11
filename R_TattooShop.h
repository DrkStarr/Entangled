! Need to put a partition in the room - explaining that Nick sleeps there

! ---------------------------------------------------------------------------- !
!       TATTOO SHOP. 06/03/19
!
  Room    tattooShop "Crazy Monkey Tattoo Shop"
   with   description [;
              if (self.firstTime) {
                  self.firstTime = false;
                  StartDaemon(tattooShopNick);
                  iRoom++;
              }
              SelfPlayer.outside = false;
              print "Music fills the room from the back, a section that's partitioned
              off. With the place cut in half, there's only one table for the artist
              to work at. A full-size mirror covers the wall behind him.
              The door out of here is north.^";
              if (self.firstTimeIn) {
                  self.firstTimeIn = false;
                  "^Nick greets you. ~How are you doing tonight,~ he asks as you walk in.";
              }
              "^Nick sits in the corner, looking over a magazine.";
          ],
          n_to [;
              <<Enter tattooShopDoor>>;
          ],
          s_to [;
              "The biker wouldn't appreciate you going into his bedroom. You can go north out of the front door.";
          ],
          cant_go [;
              "You can go north out of the front door.";
          ],
          before [;
              Exit:
                  <<Enter tattooShopDoor>>;
              Listen:
                  "Some classic rock is coming from the room in the back - stuff from the '90s.";
              Smell:
                  "A sharp iron smell lingers in the air, like leather and blood.";
              Sorry:
                  <<Answer t_sorry tattooShopNick>>;
              WaveHands:

              Yes:
                  <<Answer t_yes tattooShopNick>>;
              No:
                  <<Answer t_no tattooShopNick>>;
              Sleep:
                  return roomSleep();
        ],
        firstTime true,
        firstTimeIn true;

! 06/03/19

  RoomObj -> tattooShopObj "shop"
    with  name 'room' 'area' 'shop' 'place' 'corner',
          description [;
              <<Look tattooShop>>;
          ],
          before [;
              Search:
                  "The biker might not like that. You keep to yourself.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that.";
          ];

! 06/03/19

  Object  -> tattooShopDoor "front door"
    with  name 'front' 'door' 'frontdoor' 'scratched' 'glass',
          before [;
              Close:
                  "You don't need to do that.";
              Enter, Go, Open:
                  print "You nod to the biker heading out the door.^
                  ^~Later,~ he says.^";
                  tattooShop.firstTimeIn = true;
                  PlayerTo(outsideArtGallery);
                  rtrue;
              Examine, Search:
                  "The door's made of clear glass, but it's all scratched up - like someone painted
                  on it only to scrape it away in a half-hearted attempt. It's kept closed.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "You can't do that. It's part of the shop.";
              Rub:
                  "~I never got that cleaned. I doubt you will. Just leave it alone.~";
          ],
    has   concealed static openable ~open;

! 07/05/19

  Object -> tattooShopTable "table"
    with  name 'table',
          before [;
              Examine, Search:
                  "The table is a spot for Nick to ink people. But no one is here, so he sits at it reading - his kit on the corner.";
              Take, Remove, Turn, PushDir, Push, Pull:
                  "Nick wouldn't appreciate that.";
              Enter:
                  "~Look. I'd tattoo you if you had the cash. But I don't see any. So quit wasting my time.~";
          ],
     has  concealed static supporter;

! 07/05/19

  Object -> tattooShopMagazine "magazine"
    with  name 'magazine' 'mag',
          before [;
              Burn:
                  rfalse;
              Buy:
                  "That's not for sale.";
              Examine, Search:
                  "The magazine has a half-naked woman on the front of it. She's covered in tattoos.";
              default:
                  "That would be dumb and probably start a fight.";
          ],
     has  concealed static supporter;

! 07/05/19

  Object -> tattooShopVest "vest"
    with  name 'vest' 'leather' 'colors',
          before [;
              Burn:
                  rfalse;
              Examine, Search:
                  "Nick's wearing his vest from back in the day. It has an eagle spread across it
                  and says, ~Born To Ride.~";
              default:
                  "That would be dumb and probably start a fight.";
          ],
    has  concealed static supporter;

! 07/05/19

  Object -> tattooShopMirror "mirror"
    with  name 'full-size' 'mirror',
          before [;
              Burn:
                  rfalse;
              Examine, Search:
                  "A full-size mirror runs the length of the wall.
                  Looking into it, you wonder if you're putting on a little weight.";
              Rub:
                  "You think twice about it. In the end, you'd dirty the mirror upsetting Nick.";
              default:
                  "Nick wouldn't appreciate that.";
          ],
     has  concealed static supporter;

! 04/27/20

  Object  -> tattooShopPartition "partition"
    with  name 'partition' 'section' 'wall' 'drywall',
          before [;
              Burn:
                  rfalse;
              Examine, Search:
                  "This room is partitioned in half, creating a bedroom in the back.
                  The section made from drywall is adequately framed and covered with a mirror.";
              default:
                  "Nick wouldn't appreciate that.";
          ],
     has  concealed static;

! 04/27/20

  Object  -> tattooShopBedroom "bedroom"
    with  name 'bedroom' 'bed' 'back',
          before [;
              Examine, Search:
                  "You can't see that from here.";
              Enter, Go:
                  "That would be dumb and probably start a fight.";
              default:
                  "You can't see that from here.";
          ],
     has  concealed static;

! 06/01/20

  Object  -> tattooShopBikerTattoos "tattoos"
    with  name 'tattoo' 'tattoos' 'serpent' 'skeletal' 'head' 'heads' 'blaze' 'fire' 'tat' 'tatt',
          before [;
              Buy:
                  return AskBikerForTattoo();
              Examine, Search:
                  print "The biker is covered. A serpent slides down one arm, and a row of skeletal heads runs down the other. Underneath the skulls, a blaze of fire";
                  if (self.bikerSmile) ".";
                  self.bikerSmile = true;
                  ". He smiles to himself as he catches you looking at him.";
              default:
                  "You think twice before upsetting the biker.";
          ],
          bikerSmile false,
     has  concealed static pluralname;

! 06/03/19

  Object  -> tattooShopKit "kit"
    with  name 'kit' 'neosporin' 'cotton' 'gauze' 'tape',
          before [;
              Burn:
                  rfalse;
              Examine, Search:
                  "It has everything the old biker needs to stick people with ink. Different colors are in there, along with the gun used to inject it. Plus, some Neosporin, cotton gauze, and tape.";
              default:
                  "~Don't touch that.~";
          ],
     has  concealed static;

  Include "NPC_OldNick";
