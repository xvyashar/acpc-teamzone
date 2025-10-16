#!/usr/bin/env bash
set -e  # stop if any command fails

# --- define ANSI colors ---
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
CYAN="\033[0;36m"
RESET="\033[0m"

# --- check argument ---
if [ $# -lt 1 ]; then
  echo -e "${RED}Error:${RESET} No input file specified."
  echo -e "${YELLOW}Usage:${RESET} $0 <path-to-cpp-file>"
  exit 1
fi

SRC_PATH="$1"

# --- check if file exists ---
if [ ! -f "$SRC_PATH" ]; then
  echo -e "${RED}Error:${RESET} File not found: ${YELLOW}$SRC_PATH${RESET}"
  exit 1
fi

# --- get directory and base name ---
SRC_DIR="$(dirname "$SRC_PATH")"
SRC_FILE="$(basename "$SRC_PATH")"
EXE_NAME="${SRC_FILE%.cpp}"

# --- define temporary output path ---
if [ ! -d "./tmp" ]; then
  mkdir "tmp"
fi
OUT_PATH="./tmp/${EXE_NAME}"

# --- compile with g++ ---
echo -e "${CYAN}Compiling${RESET} ${YELLOW}$SRC_FILE${RESET} ..."
g++ -std=c++17 -O2 -Wall "$SRC_PATH" -o "$OUT_PATH"
echo -e "${GREEN}✓ Compilation successful!${RESET}"

# --- locate input.txt next to source ---
INPUT_FILE="${SRC_DIR}/input.txt"

if [ -f "$INPUT_FILE" ]; then
  echo -e "${CYAN}Running${RESET} with input from: ${YELLOW}$INPUT_FILE${RESET}"
  echo -e "${CYAN}---------------- OUTPUT ----------------${RESET}"
  "$OUT_PATH" < "$INPUT_FILE"
else
  echo -e "${YELLOW}No input.txt found${RESET} next to ${YELLOW}$SRC_FILE${RESET}"
  echo -e "${CYAN}Running interactively...${RESET}"
  echo -e "${CYAN}------------------------------------${RESET}"
  "$OUT_PATH"
fi
