# Allegro starter kit

## RICORDATI:

~~La lib allegro-tiled va compliata dinamicamente, altrimenti non funziona, intule ca vatti!!!~~
RIMOSSA!

---

### TODO

- [x] ~~sistemare la gerarchia delle classi entities, enemy e player in modo che ci sia coerenza~~
- [ ] fullscreen
- [ ] ~~mappa corretta~~ troppo pensante con le trasparenze, risolvere!
- [ ] collisioni con la mappa
- [ ] ~~arma~~
- [ ] ai nemica (insegue ma va rivista)

---

**fullscreen** queste righe di codice fanno un simpaticissimo toggle

```cpp
// toggle fullscreen
al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, !(al_get_display_flags(display) & ALLEGRO_FULLSCREEN_WINDOW));
```

---
