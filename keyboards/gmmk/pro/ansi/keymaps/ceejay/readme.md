# ceejay's GMMK Pro layout

## Layers

- 3 macOS/ 1 Windows base layers
- `FN` layer (OS-specific), accessed by holding `FN`
- "System" layer (global), accessed by holding `ESC`

## Global Keys (valid for all base layers)
Keys in this section are valid for all Windows and macOS base layers.

### Base layer
- `CAPS LOCK`: hold for `CTRL`, tap for `CAPS LOCK`
- Key to the left of the rotary encoder is `DEL`
- Encoder:
    - `Rotate`: adjust volume
    - `Click`:  media pause/play

### FN layer
The following keys are accessible by holding `FN` on all base layers:
- `ESC`: toggle RGB
- `~`: toggle Scroll lock
- `TAB`: toggle Num lock
- `Q`/`A`: Increase/Decrease RGB saturation
- `W`/`S`: Increase/Decrease RGB brightness
- `E`/`D`: Increase/Decrease RGB speed
- `N`: toggle N-key rollover
- `LEFT`/`RIGHT`: change RGB hue
- `UP`/`DOWN`: change RGB effect
- `HOME`/`END`: Media Next/Prev track
- Encoder:
    - `Rotate`: adjust brightness (mapped to `WIN`+`SHIFT`+`-`/`=` on Windows, native `Brightness Down`/`Brightness Up` on macOS)

### System layer
The following keys are accessible by holding `ESC` on all base layers:
- `W`: switch base layer to Windows (saved to EEPROM)
- `M`: cycle through macOS layers (e.g layer 1 > layer 2 > layer 3 > layer 1 > etc.) (saved to EEPROM)
- `,`/`.`: decrease/increase RGB timeout in minutes
- `\`: QMK `RESET` button
- `HOME`: Wake button (probably useless, works only on macOS)
- `PGDN`/`BREAK`: Sleep button (tap on Windows, hold on macOS)
- `END`: Shutdown button (tap on Windows, hold on macOS)
- Encoder:
    - `Rotate`: adjust RGB timeout in minutes

## Windows
The 4 keys below the encoder are, from top to bottom:
- `HOME`
- `INS` (for IntelliJ shortcuts)
- `BREAK` (does nothing, can be mapped to mute/unmute on Discord)
- `END`

### FN Layer
Windows-specific keys on the FN layer are:
- `WIN`: toggle Win lock
- `L`: lock screen (WIN+L)
- `F12`: open calculator
- `DEL`: Print Screen (can be mapped to Snipping Tool on OS settings)
- `INS`: Page Up
- `BREAK`: Page Down
- Encoder `Click`: Media Stop
 
## macOS
 There are 3 alternate macOS layers. The only difference is placement of modifier keys: `^` (Ctrl), `⌘` (Cmd), `⌥` (Opt).
 
 - **Layer 1**: standard layout
   - Left modifiers (from left to right): `^`, `⌥`, `⌘`
   - Right modifiers (from left to right): `⌘`, `FN`, `^`
 - **Layer 2**: "Windows-like" layout
   - Left modifiers (left to right): `⌘`, `^`, `⌥`
   - Right modifiers (left to right): `⌥`, `FN`, `⌘`
 - **Layer 3**: "Swapped Ctrl and Cmd" layout
   - Left modifiers: `⌘`, `⌥`, `^`
   - Right modifiers: `⌘`, `FN`, `^`

### Base layer
The 4 keys below the encoder are, from top to bottom:
- `HOME`
- `PGUP`
- `PGDN`
- `END`

### FN Layer
macOS-specific keys on the FN layer are (`⇧` stands for `SHIFT`):
- `L`: lock screen (`^` `⌘` `Q`)
- `F12`: open screenshot app (`⌘` `⇧` `4`)
- `DEL`: screenshot of region, saved to clipboard (`^` `⌘` `⇧` `5`)
- Encoder `Click`: Mute/Unmute audio output

## RGB
- Caps/Num/Scroll/Win lock are highlighted in **red** when active on left-side LEDs.
- `FN` layer is highlighted in **red** when active on right-side LEDs
- Mapped keys in `FN`/System layers are highlighted in white
- System layer:
    - `W` key is **red** when Windows layout is active
    - `M` key is **red** when macOS **layer 1** is active
    - `N` and `M` keys are **red** when macOS **layer 2** is active
    - `B`, `N` and `M` keys are **red** when macOS **layer 3** is active
    - RGB timeout is highlighted in **red** on function row (e.g. `F5` = 5 minutes, `F10` = 10 minutes).
        - When above 10 minutes, tens are highlighted on function row, units on number row (e.g. `F4`+`5` = 45 minutes)
