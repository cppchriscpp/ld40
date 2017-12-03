;this file for FamiTone2 library generated by text2data tool

music_music_data:
	.byte 4
	.word @instruments
	.word @samples-3
	.word @song0ch0,@song0ch1,@song0ch2,@song0ch3,@song0ch4,307,256
	.word @song1ch0,@song1ch1,@song1ch2,@song1ch3,@song1ch4,307,256
	.word @song2ch0,@song2ch1,@song2ch2,@song2ch3,@song2ch4,307,256
	.word @song3ch0,@song3ch1,@song3ch2,@song3ch3,@song3ch4,307,256

@instruments:
	.byte $30 ;instrument $00
	.word @env1,@env0,@env0
	.byte $00
	.byte $30 ;instrument $01
	.word @env2,@env4,@env0
	.byte $00
	.byte $30 ;instrument $02
	.word @env2,@env5,@env0
	.byte $00
	.byte $b0 ;instrument $03
	.word @env3,@env0,@env6
	.byte $00

@samples:
@env0:
	.byte $c0,$00,$00
@env1:
	.byte $c4,$00,$00
@env2:
	.byte $c4,$c7,$c9,$ca,$cb,$cc,$cb,$c9,$00,$07
@env3:
	.byte $c3,$02,$c2,$00,$02
@env4:
	.byte $c0,$c1,$c2,$c3,$c4,$c5,$c7,$c9,$00,$07
@env5:
	.byte $c9,$c8,$c7,$c6,$c4,$c3,$c2,$c0,$00,$07
@env6:
	.byte $eb,$ff,$02,$ff,$00,$03


@song0ch0:
	.byte $fb,$06
@song0ch0loop:
@ref0:
	.byte $80,$28,$85,$30,$85,$36,$85,$31,$29,$29,$29,$30,$85,$36,$85,$2c
	.byte $85,$28,$85,$30,$85,$36,$85,$30,$85,$28,$85,$26,$85,$28,$85,$00
	.byte $85
	.byte $fd
	.word @song0ch0loop

@song0ch1:
@song0ch1loop:
@ref1:
	.byte $f9,$85
	.byte $fd
	.word @song0ch1loop

@song0ch2:
@song0ch2loop:
@ref2:
	.byte $f9,$85
	.byte $fd
	.word @song0ch2loop

@song0ch3:
@song0ch3loop:
@ref3:
	.byte $f9,$85
	.byte $fd
	.word @song0ch3loop

@song0ch4:
@song0ch4loop:
@ref4:
	.byte $f9,$85
	.byte $fd
	.word @song0ch4loop


@song1ch0:
	.byte $fb,$04
@ref5:
	.byte $82,$52,$4e,$4a,$48,$44,$40,$3c,$3a,$36,$32,$30,$2c,$28,$24,$00
	.byte $e1
@song1ch0loop:
@ref6:
	.byte $81
	.byte $fd
	.word @song1ch0loop

@song1ch1:
@ref7:
	.byte $f9,$85
@song1ch1loop:
@ref8:
	.byte $81
	.byte $fd
	.word @song1ch1loop

@song1ch2:
@ref9:
	.byte $f9,$85
@song1ch2loop:
@ref10:
	.byte $81
	.byte $fd
	.word @song1ch2loop

@song1ch3:
@ref11:
	.byte $9d,$84,$19,$00,$db
@song1ch3loop:
@ref12:
	.byte $81
	.byte $fd
	.word @song1ch3loop

@song1ch4:
@ref13:
	.byte $f9,$85
@song1ch4loop:
@ref14:
	.byte $81
	.byte $fd
	.word @song1ch4loop


@song2ch0:
	.byte $fb,$02
@ref15:
	.byte $82,$1a,$1e,$22,$24,$28,$2c,$30,$32,$36,$3a,$3c,$40,$44,$48,$4a
	.byte $4e,$52,$54,$58,$5c,$60,$62,$00,$d1
@song2ch0loop:
@ref16:
	.byte $81
	.byte $fd
	.word @song2ch0loop

@song2ch1:
@ref17:
	.byte $f9,$85
@song2ch1loop:
@ref18:
	.byte $81
	.byte $fd
	.word @song2ch1loop

@song2ch2:
@ref19:
	.byte $f9,$85
@song2ch2loop:
@ref20:
	.byte $81
	.byte $fd
	.word @song2ch2loop

@song2ch3:
@ref21:
	.byte $f9,$85
@song2ch3loop:
@ref22:
	.byte $81
	.byte $fd
	.word @song2ch3loop

@song2ch4:
@ref23:
	.byte $f9,$85
@song2ch4loop:
@ref24:
	.byte $81
	.byte $fd
	.word @song2ch4loop


@song3ch0:
	.byte $fb,$08
@song3ch0loop:
@ref25:
	.byte $f9,$85
@ref26:
	.byte $a1
	.byte $fd
	.word @song3ch0loop

@song3ch1:
@song3ch1loop:
@ref27:
	.byte $86,$03,$01,$03,$01,$0a,$10,$0b,$01,$03,$00,$85,$03,$01,$03,$01
	.byte $0a,$10,$0b,$01,$07,$00,$85,$03,$01,$03,$01,$0a,$10,$0b,$01,$03
	.byte $00,$85,$03,$00,$81
@ref28:
	.byte $0b,$00,$85,$0b,$01,$03,$00,$87
	.byte $fd
	.word @song3ch1loop

@song3ch2:
@song3ch2loop:
@ref29:
	.byte $f9,$85
@ref30:
	.byte $a1
	.byte $fd
	.word @song3ch2loop

@song3ch3:
@song3ch3loop:
@ref31:
	.byte $f9,$85
@ref32:
	.byte $a1
	.byte $fd
	.word @song3ch3loop

@song3ch4:
@song3ch4loop:
@ref33:
	.byte $f9,$85
@ref34:
	.byte $a1
	.byte $fd
	.word @song3ch4loop
