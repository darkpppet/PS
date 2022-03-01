#!/bin/bash

cd /usr/lib/code-server

# update style-src
grep -rl "style-src 'self' 'unsafe-inline'" . | sudo xargs sed -i "s/style-src 'self' 'unsafe-inline'/style-src 'self' 'unsafe-inline' fonts.googleapis.com/g"
# update font-src
grep -rl "font-src 'self' blob:" . | sudo xargs sed -i "s/font-src 'self' blob:/font-src 'self' blob: fonts.gstatic.com/g"