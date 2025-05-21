#!/usr/bin/env bash
set -euo pipefail

# ——— CONFIG ———
DEST="../Done"
REMOTE="origin"
BRANCH=$(git rev-parse --abbrev-ref HEAD)
SCRIPT_NAME="Executor.sh"
# ————————

i=1
while true; do
  # pick the “last” file in this directory, excluding the script itself
  file=$(ls -1A | grep -vFx "$SCRIPT_NAME" | tail -n1) || file=""
  [ -z "$file" ] && break   # no files left → exit

  echo "--> Moving '$file' to '$DEST/' (commit #$i)"
  mv -- "$file" "$DEST/"

  # Stage everything (moves, adds, deletes)
  git add -A

  git commit -m "$i"
  git push "$REMOTE" "$BRANCH"

  ((i++))
done

echo "Done. Moved and committed $((i-1)) files."
