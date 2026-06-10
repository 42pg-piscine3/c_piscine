#!/bin/bash
# lists all the existing files ignored by your Git repository
# ignored - show ignored files
# cached / others - will be prompted if ignored is used standalone
# --exclude-standard - apply all ignore rules
# ":/" is the shortcut for git top level
git ls-files --ignored --cached --others --exclude-standard ":/"

