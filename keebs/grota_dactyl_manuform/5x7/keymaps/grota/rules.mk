.PHONY: asciiart

asciiart:
	keymapviz -k dactyl_manuform5x7 -t fancy -r keebs/grota_dactyl_manuform/5x7/keymaps/grota/keymap.c -c keebs/grota_dactyl_manuform/5x7/keymaps/grota/keymapviz.labels
	rm keebs/grota_dactyl_manuform/5x7/keymaps/grota/keymap.c.bac
