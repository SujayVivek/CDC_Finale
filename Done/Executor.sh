#!/usr/bin/env bash
set -euo pipefail

# ——— CONFIG ———
DEST="../Done"
REMOTE="origin"
BRANCH=$(git rev-parse --abbrev-ref HEAD)
# ————————

script_name=$(basename "$0")
i=1

while true; do
  # pick the “last” filename
  file=$(ls -1A | tail -n1) || file=""
  [ -z "$file" ] && break

  # skip the script itself
  if [ "$file" = "$script_name" ]; then
    # remove it from consideration for this iteration,
    # and pick the next one instead:
    ls -1A | grep -vFx "$script_name" | tail -n1 | read -r file
    [ -z "$file" ] && break
  fi

  echo "--> Moving '$file' to '$DEST/' (commit #$i)"
  mv -- "$file" "$DEST/"

  git add -- "$DEST/$file"
  git rm --cached -- "$file"

  git commit -m "$i"
  git push "$REMOTE" "$BRANCH"

  ((i++))
done

echo "Done. Moved and committed $((i-1)) files."
