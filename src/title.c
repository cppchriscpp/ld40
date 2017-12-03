#include "src/globals.h"
#include "lib/neslib.h"
#include "lib/boilerplate.h"
#include "bin/build_info.h"
#pragma rodataseg ("ROM_00")
#pragma codeseg ("ROM_00")
const unsigned char titlePalette[16] = { 0x0f,0x21,0x21,0x31,0x0f,0x01,0x21,0x31,0x0f,0x06,0x16,0x26,0x0f,0x09,0x19,0x29 };



void banked_draw_title() {
	ppu_off();
	pal_bg(titlePalette);
	pal_bright(0);

	set_chr_bank_0(CHR_BANK_TITLE);
	set_chr_bank_1(CHR_BANK_TITLE+1);
	clear_screen();

	// Show a message to the user.
	put_str(NTADR_A(2,8), "Fluffy Space Escape");
	put_str(NTADR_A(2,12), "Ludum Dare 40 Entry");
	put_str(NTADR_A(2,20), "Press Start to play");

	// Also show some cool build info because we can.
	#if SHOW_VERSION_INFO
		put_str(NTADR_A(2,24), "Built: " BUILD_DATE);
		put_str(NTADR_A(2,25), "Build #" BUILD_NUMBER_STR " (" GIT_COMMIT_ID_SHORT " - " GIT_BRANCH ")");
		put_str(NTADR_A(2,26), "Commit counter: " COMMIT_COUNT_STR);
		#if DEBUG
			put_str(NTADR_A(6,28), "DEBUG MODE ENABLED");
		#endif
	#endif
	ppu_on_all();
	animate_fadein(5);
}

void banked_do_title() {
	scratch = pad_trigger(0);
	if (scratch & (PAD_A | PAD_START)) {
		gameState = GAME_STATE_POST_START;
	}

}

void banked_draw_instructions() {
	animate_fadeout(5);
	ppu_off();
	pal_bg(titlePalette);

	set_chr_bank_0(CHR_BANK_TITLE);
	set_chr_bank_1(CHR_BANK_TITLE+1);
	clear_screen();

	vram_adr(NTADR_A(3, 2));
	vram_put(HUD_TL);
	vram_fill(HUD_H, 23);
	vram_put(HUD_TR);

	for (i = 3; i < 26; ++i) {
		vram_adr(NTADR_A(3, i));
		vram_put(HUD_V);
		vram_fill(HUD_BLANK, 23);
		vram_put(HUD_V);
	}

	vram_adr(NTADR_A(3, 26));
	vram_put(HUD_BL);
	vram_fill(HUD_H, 23);
	vram_put(HUD_BR);


	put_str(NTADR_A(6, 2), "Fluffy Space Escape");
	put_str(NTADR_A(5,6),  "The year is 2248.");
	put_str(NTADR_A(5,7), "You are a rabbit, and");
	put_str(NTADR_A(5,8), "have been transported");
	put_str(NTADR_A(5,9), "into space after a");
	put_str(NTADR_A(5,10), "teleporter mishap.");

	put_str(NTADR_A(5,12), "You must fight your");
	put_str(NTADR_A(5,13), "way through space to");
	put_str(NTADR_A(5,14), "make your way home.");

	put_str(NTADR_A(5,16), "You can use gems to");
	put_str(NTADR_A(5,17), "activate teleporters,");
	put_str(NTADR_A(5,18), "but beware; they are");
	put_str(NTADR_A(5,19), "heavy! If you carry");
	put_str(NTADR_A(5,20), "too many, you will");
	put_str(NTADR_A(5,21), "slow down a lot!");

	put_str(NTADR_A(10,24), "Good luck!");

	ppu_on_all();
	animate_fadein(5);
}

void banked_do_instructions() {
	while (1) {
		scratch = pad_trigger(0);
		if (scratch & (PAD_A | PAD_START)) {
			break;
		}
		ppu_wait_frame();
	}

}

void banked_show_level_complete() {

	ppu_off();
	pal_bg(titlePalette);
	set_chr_bank_0(CHR_BANK_TITLE);
	set_chr_bank_1(CHR_BANK_TITLE+1);

	set_vram_update(NULL); // STOP HELPING, ENGINE
	clear_screen();
	oam_clear();

	vram_adr(NTADR_A(6, 11));
	vram_put(HUD_TL);
	vram_fill(HUD_H, 17);
	vram_put(HUD_TR);
	vram_adr(NTADR_A(6, 12));
	vram_put(HUD_V);
	vram_fill(HUD_BLANK, 17);
	vram_put(HUD_V);
	vram_adr(NTADR_A(6, 13));
	vram_put(HUD_V);
	put_str(NTADR_A(8, 13), "Level Complete!");
	vram_put(HUD_BLANK);
	vram_put(HUD_V);
	vram_adr(NTADR_A(6, 14));
	vram_put(HUD_V);
	vram_fill(HUD_BLANK, 17);
	vram_put(HUD_V);
	vram_adr(NTADR_A(6, 15));
	vram_put(HUD_BL);
	vram_fill(HUD_H, 17);
	vram_put(HUD_BR);

	ppu_on_all();

}

void banked_do_level_complete() {
	// TODO: timeout after x rounds.
	while (1) {
		scratch = pad_trigger(0);
		if (scratch & (PAD_A | PAD_START)) {
			gameState = GAME_STATE_POST_START;
			break;
		}
		ppu_wait_frame();
	}
}

void banked_draw_dead() {
	ppu_off();
	pal_bg(titlePalette);
	set_chr_bank_0(CHR_BANK_TITLE);
	set_chr_bank_1(CHR_BANK_TITLE+1);

	set_vram_update(NULL); // STOP HELPING, ENGINE
	clear_screen();
	oam_clear();

    vram_adr(NAMETABLE_A + 0x03c0);
    vram_fill(0xaa, 0x40);

	vram_adr(NTADR_A(6, 11));
	vram_put(HUD_TL);
	vram_fill(HUD_H, 17);
	vram_put(HUD_TR);

	vram_adr(NTADR_A(6, 12));
	vram_put(HUD_V);
	vram_fill(HUD_BLANK, 17);
	vram_put(HUD_V);

	vram_adr(NTADR_A(6, 13));
	vram_put(HUD_V);
	put_str(NTADR_A(9, 13), "Bunny Didn't"); 
	vram_fill(HUD_BLANK, 3);
	vram_put(HUD_V);

	vram_adr(NTADR_A(6, 14));
	vram_put(HUD_V);
	put_str(NTADR_A(10, 14), "Make it...");
	vram_fill(HUD_BLANK, 4);
	vram_put(HUD_V);


	vram_adr(NTADR_A(6, 15));
	vram_put(HUD_V);
	vram_fill(HUD_BLANK, 17);
	vram_put(HUD_V);

	vram_adr(NTADR_A(6, 16));
	vram_put(HUD_BL);
	vram_fill(HUD_H, 17);
	vram_put(HUD_BR);

	ppu_on_all();
}

void banked_do_dead() {
	// TODO: timeout after x rounds.
	while (1) {
		scratch = pad_trigger(0);
		if (scratch & (PAD_A | PAD_START)) {
			gameState = GAME_STATE_POST_START;
			break;
		}
		ppu_wait_frame();
	}

}


void banked_draw_win() {
	ppu_off();
	pal_bg(titlePalette);

	set_chr_bank_0(CHR_BANK_TITLE);
	set_chr_bank_1(CHR_BANK_TITLE+1);
	clear_screen();

	// Show a message to the user.

	vram_adr(NTADR_A(4, 2));
	vram_put(HUD_TL);
	vram_fill(HUD_H, 22);
	vram_put(HUD_TR);

	for (i = 3; i < 26; ++i) {
		vram_adr(NTADR_A(4, i));
		vram_put(HUD_V);
		vram_fill(HUD_BLANK, 22);
		vram_put(HUD_V);
	}

	vram_adr(NTADR_A(4, 26));
	vram_put(HUD_BL);
	vram_fill(HUD_H, 22);
	vram_put(HUD_BR);



	put_str(NTADR_A(8, 2), "Congratulations!");
	put_str(NTADR_A(6,5),  "Our hero was able to");
	put_str(NTADR_A(6,6), "return home safely");
	put_str(NTADR_A(6,7), "thanks to your quick");
	put_str(NTADR_A(6,8), "quick thinking!");

	put_str(NTADR_A(6,10), "Your quest is now");
	put_str(NTADR_A(6,11), "over.");
	
	put_str(NTADR_A(12, 13), "- Stats -");
	if (deathCounter == 0) {
		put_str(NTADR_A(6, 15), "Deaths: NONE!");
	} else {
		put_str(NTADR_A(6, 15), "Deaths: ");
		set_vram_update(NULL);
		itoa(deathCounter, &screenBuffer[0]);
		for (i = 0; i < 8 && screenBuffer[i] != '\0'; ++i) {
			vram_put(screenBuffer[i] - 0x20);
		}
	}
	put_str(NTADR_A(6,16), "Built " BUILD_DATE_ONLY);
	put_str(NTADR_A(6,17), "       " BUILD_TIME_ONLY);
	put_str(NTADR_A(6,18), "Build: " BUILD_NUMBER_STR " (" GIT_COMMIT_ID_SHORT ")");
	put_str(NTADR_A(6,20), "Made in 48 hours");
	put_str(NTADR_A(6,21), "for Ludum Dare 40");

	put_str(NTADR_A(6,24), "Thanks for playing!");


	ppu_on_all();	
}

void banked_do_win() {
	while (1) {
		scratch = pad_trigger(0);
		if (scratch & (PAD_A | PAD_START)) {
			gameState = GAME_STATE_INIT;
			break;
		}
		ppu_wait_frame();
	}

}
