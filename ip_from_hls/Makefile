FOLDERS  = $(find . -maxdepth 1 -mindepth 1 -type d)
ARCHIVES = $(find . -maxdepth 1 -mindepth 1 -type f -name '*.zip')

.PHONY	: clean clean_dir clean_zip
clean_dir:
	rm -rf $(value FOLDERS)  

clean_zip:
	rm -rf $(value ARCHIVES)

clean: clean_dir clean_zip

