#ifndef MONKEY_H
#define MONKEY_H

#define MONKEY_FPS 7
#define MONKEY_WIDTH 21
#define MONKEY_HEIGHT 11
#define MONKEY_REPEAT true

#define MONKEY_FRAME_COUNT 15
const wchar_t* MONKEY_FRAMES =
  L"                     "
  L"        ,,,          "
  L"      -(°_°)-     ___"
  L"   _...-/ \\.._   /_- "
  L"  //''( . . )\\\\ //   "
  L" ||    \\ . /  \\V/    "
  L"|,,|   | _ |_        "
  L"       || ''\\\\       "
  L"       \\\\   //_      "
  L"      _//   '''      "
  L"     '''             "

  L"                     "
  L"        ,,,          "
  L"      -(°_°)-        "
  L"  .=--.-/ \\.._   ___ "
  L" || ''( . . )\\\\ /_-  "
  L"./\\.   \\ . /  \\_/    "
  L"''''   | _ |         "
  L"       // '\\\\        "
  L"      ||   ||        "
  L"     ''    '''       "

  L"                     "
  L"         ,,,         "
  L"       -(^_^)-       "
  L"  ,--,._/ |.._       "
  L" /,'',( . . )||      "
  L"\\.\\'   \\ . /  \\\\--.  "
  L"      _| _ |    '''  "
  L"     //'  ||         "
  L"    _\\\\   ||         "
  L"    '''   \\\\_        "
  L"           '''       "

  L"                     "
  L"         ,,,         "
  L"       -(°_°)-       "
  L"|''| ,._/ /.._       "
  L" ||_//( . . )\\\\      "
  L"  \\_/  \\ . /  \\\\ _   "
  L"       | _ |   (,,)  "
  L"     //'  ||         "
  L"   _//    ||         "
  L"   '''    \\\\_        "
  L"           '''       "

  L"                     "
  L"         ,,,         "
  L"\\\\\\    -(°o°)-       "
  L" ||  ,._/ /.._       "
  L" \\\\_//( . . )\\\\      "
  L"  '''  \\ . /  \\\\_    "
  L"       | _ |  /,,/   "
  L"     //'  ||         "
  L"  .\\//    ||         "
  L"   ''     \\\\_        "
  L"           '''       "

  L"                     "
  L"        ,,,          "
  L" ///  -(°_°)-        "
  L" ||  ,._| |.._       "
  L" \\\\_//( . . )\\\\      "
  L"  '''  \\ . /  \\\\     "
  L"       | _ | (,,)    "
  L"     //'  ||         "
  L"   _//    ||         "
  L"   '''    \\\\_        "
  L"           '''       "

  L"                     "
  L"  ,,,  ,,,           "
  L"  ||'-(°_°)-         "
  L"  ||_,.\\ \\.._        "
  L"   \\_/( . . )\\\\      "
  L"       \\ . / _\\\\     "
  L"       | _ | =_/     "
  L"     //'  ||         "
  L"  .\\//    ||         "
  L"   ''     \\\\_        "
  L"           '''       "

  L"  ,,,                "
  L"  ||'  ,,,           "
  L"  || -(°_°)-         "
  L"   \\\\,.\\ \\.._        "
  L"    ''( . . )\\\\      "
  L"       \\ . /.||      "
  L"       | _ |'''      "
  L"     //'  ||         "
  L"   _//    ||         "
  L"   '''    \\\\_        "
  L"           '''       "

  L"                     "
  L"  ,,,   ,,,          "
  L"  ||' -(^_^)-        "
  L"  ||_ ,.| |.._       "
  L"   \\_/( . . )\\\\      "
  L"       \\ . /.//      "
  L"       | _ |''       "
  L"     //'  ||         "
  L"     ||   ||         "
  L"     /'   \\\\_        "
  L"           '''       "

  L"  ,,,                "
  L"  ||'    ,,,         "
  L"  ||   -(°_°)-       "
  L"   \\\\ ,./ /.._       "
  L"    ''( . . )\\\\      "
  L"       \\ . /.//      "
  L"       | _ |''       "
  L"      //  \\\\         "
  L"      \\\\  //         "
  L"      /'  \\\\_        "
  L"      ''   '''       "

  L"                     "
  L"  ,,,    ,,,         "
  L"  ||'  -(O_O)-       "
  L"  ||_ ,./ /.._       "
  L"   \\_/( . . )\\\\      "
  L"       \\ , / ||      "
  L"        )_ ) '))     "
  L"       //  \\\\        "
  L"       \\\\  //        "
  L"      _//  '\\        "
  L"     '''   ''        "

  L"                     "
  L"         ,,,         "
  L"  ,,,  -(o_o)-       "
  L"  ||' ,./ /.._       "
  L"  \\\\//( . . )\\\\      "
  L"   ''  \\ . /  \\\\     "
  L"       | _ |  ('')   "
  L"      //  \\\\         "
  L"      \\\\  //         "
  L"      /'  \\\\_        "
  L"      ''  '''        "

  L"                     "
  L"        ,,,          "
  L"      -(-_-)-        "
  L"  ,,, ,./ \\.._       "
  L"  \\\\'/( . . )\\\\      "
  L"   \\V/ \\ , /  \\()))  "
  L"        )_ )         "
  L"       //  \\\\        "
  L"       \\\\  //        "
  L"      _//  '\\        "
  L"     '''   ''        "

  L"                     "
  L"        ,,,          "
  L"      -(0_0)-        "
  L"      ,./ \\.._       "
  L" ('')/( . . )\\\\('')  "
  L"  \\\\// \\ . /  \\V/    "
  L"   ''  | _ |         "
  L"       //  \\\\        "
  L"       \\\\   ||       "
  L"      _//   \\\\       "
  L"     '''     ''      "

  L"                     "
  L"        ,,,          "
  L"      -(°_°)-        "
  L"      ,./ \\.._    __ "
  L"     /( . . )\\\\  /_/ "
  L" ('')/ \\ . /  \\\\//   "
  L"  '''  | _ |         "
  L"       //  \\\\        "
  L"       \\\\   ||       "
  L"      _//   '''      "
  L"     '''             "
;

#endif
