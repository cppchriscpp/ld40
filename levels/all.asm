.export _lvl_details

.segment "ROM_02"
	_lvl_details: ; NOTE: This only exists here, but applies for all banks. DON'T CHANGE THE SIZE w/o considering this
	; Start location; tileId, x, y, Number of chunks
	.byte 27, 80, 80, 3
	.include "levels/processed/lvl1_tiles.asm"
