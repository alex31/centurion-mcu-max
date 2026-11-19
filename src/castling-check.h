/* CPU6 integration correction: castling cannot start in check or cross an
   attacked square. Called only after the original virgin-rook/empty-path tests.
   Attack geometry includes pinned attackers, as required for king moves. */
static bool mcumax_attacked(uint8_t square, uint8_t side)
{
    static const int8_t rays[8] = {-16,-1,1,16,-17,-15,15,17};
    static const int8_t knights[8] = {-33,-31,-18,-14,14,18,31,33};
    uint8_t enemy = side ^ 0x18;
    uint8_t i, piece, type, distance;
    int position;
    for (i=0;i<8;i++) {
        position = (int)square + knights[i];
        if (!(position & MCUMAX_BOARD_MASK)) {
            piece = mcumax.board[position];
            if ((piece & enemy) && (piece & 7) == MCUMAX_KNIGHT) return true;
        }
    }
    for (i=0;i<8;i++) {
        position = square;
        distance = 0;
        while (1) {
            position += rays[i];
            if (position & MCUMAX_BOARD_MASK) break;
            distance++;
            piece = mcumax.board[position];
            if (!piece) continue;
            if (piece & enemy) {
                type = piece & 7;
                if (type == MCUMAX_QUEEN ||
                    (i < 4 && type == MCUMAX_ROOK) ||
                    (i >= 4 && type == MCUMAX_BISHOP)) return true;
                if (distance == 1) {
                    if (type == MCUMAX_KING) return true;
                    if (i >= 4 &&
                        ((rays[i] > 0 && type == MCUMAX_PAWN_UPSTREAM) ||
                         (rays[i] < 0 && type == MCUMAX_PAWN_DOWNSTREAM))) return true;
                }
            }
            break;
        }
    }
    return false;
}
