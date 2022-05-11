
! ---------------------------------------------------------------------------- !
!       DOORMAN. 01/23/18
!

  Object  -> outsideComplexDoorman "doorman"
    with  name 'man' 'guy' 'doorman',
          describe [;
              rtrue;
          ],
          before [ w1;
              Ask, AskCreatureFor, Answer, Talk:
                  return DoormanResponse();
              Examine:
                  if (basement.firstTime) {
                      if (outsideComplexDoor.cigOut)
                          "The doorman is a little lax, standing outside the building with his hands in his pockets.";
                      "The doorman is a little lax, standing outside smoking a cigarette.";
                  }
                  "The doorman watches people come and go from the building, paying
                  attention to everything like a hawk.";
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                  }
                  return DoormanResponse();
              SmellNoun:
                  "You'd look strange smelling him.";
              Kick: rfalse;
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  return DoormanResponse();
              Take:
                  "You know he's not an object?";
              default:
                  return DoormanResponse();
          ],
          life [;
              return DoormanResponse();
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              default:
                  return DoormanResponse();
          ],
          spokeFirstTime false,
    has   animate male concealed;

  [ DoormanResponse;
        if (outsideComplexDoorman.spokeFirstTime) "~Like I said. Move along. Move along.~";
        outsideComplexDoorman.spokeFirstTime = true;
        "~Look. I'm not your friend. You don't live here. Move along.~";
  ];
