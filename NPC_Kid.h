
! ---------------------------------------------------------------------------- !
!       KID. 02/01/20 - real name Mel
!
!       Age: 12

  Object  convenienceStoreKid "kid"
    with  name 'kid' 'boy' 'child' 'mel' 'tween',
          describe [;
              rtrue;
          ],
          before [ w1;
              Ask, AskCreatureFor, Answer, Talk:
                  return KidResponse();
              Examine:
                  "The kid looks young, probably not even a teen, and he's badgering
                  the clerk trying to get a comic out of her. You wonder if he'd
                  take anything else.";
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
                  return KidResponse();
              Kick: rfalse;
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Rub, Touch, Pet:
                  "The kid slips away, twisting out of your reach.";
              SmellNoun:
                  "You'd look strange smelling him.";
              Kiss:
                  "That's wrong.";
              WaveObject:
                  return KidResponse();
              Take:
                  "You know he's not an object?";
              default:
                  return KidResponse();
          ],
          life [;
              return KidResponse();
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              default:
                  return KidResponse();
          ],
          talkedToKid false,
    has   animate male concealed;

  [ KidResponse;
        if (convenienceStoreKid.talkedToKid) "~I'm not talking to you. I got serious business here. Leave me alone.~";
        convenienceStoreKid.talkedToKid = true;
        "~Look, I got serious business going on. Give me a minute.~";
  ];
