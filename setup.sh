#!/bin/bash

# Auteur : GILLIER Théophile

cd treelib/ && make treelib && cd ..
make treesearch treeload
gnome-terminal --window -t Treeload --execute "./treeload"