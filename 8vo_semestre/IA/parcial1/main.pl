% Parcial 1 : Carlos Daniel Agamez Palomino T00059006

% Hechos -------------------------------
% variables para definicion de restricciones 
hora_inicio_servicio(13, 0). % Hora de inicio de servicio: 13:00
hora_fin_servicio(18, 0). % Hora de fin de servicio: 18:00


% Declaraciones dynamic para hacer los hechos dinámicos
:- dynamic usuario/1.
:- dynamic anfitrion/1.
:- dynamic fecha/3.
:- dynamic hora/2.
:- dynamic canal/1.
:- dynamic cita/10.

% anfitriones disponibles
anfitrion(andres).
anfitrion(jose).
anfitrion(ana).

% usuarios 
usuario(juan).
usuario(alberto).
usuario(estela).

% Predicado para agregar una cita si no existe de forna dinamica 
agregar_cita(U, A, D, M, Y, C) :-
    % Verificar si hay citas para el anfitrión en ese día
    (citas_anfitrion_ese_dia(A, D, M, Y) ->
        % Encontrar la última cita del anfitrión en ese día
        findall((Hc, MINc), cita(usuario(_), anfitrion(A), fecha(D, M, Y), hora(Hc, MINc), _, _), Citas),
        last(Citas, UltimaCita),
        % Obtener la hora y minuto de finalización de la última cita y asignamos la hora y minuto de inicio de la nueva cita
        nth0(0, UltimaCita, H),
        nth0(1, UltimaCita, MIN),
    ;   % Si no hay citas previas, asignar la hora de inicio como 13:00
        H is 13,
        MIN is 0,
    ),
    % asignamos una hora de finalizacion de cita para q cumpla con las restricciones 
    hora_finalizacion_cita(H, MIN, HF, MINF),
    % agregamos los echos 
    assertz(atiende(A, U)),
    assertz(fecha(D, M, Y)),
    assertz(hora(H, MIN)),
    assertz(hora(HF, MINF)),
    assertz(canal(C, U)),
    % agregamos la cita
    assertz(cita(usuario(U), anfitrion(A), fecha(D, M, Y), hora(H, MIN), hora(HF, MINF), canal(C))).

% Regla para obtener todas las citas de un anfitrión en un día específico
citas_anfitrion_ese_dia(A, D, M, Y) :-
    findall(_, cita(usuario(_), anfitrion(A), fecha(D, M, Y), hora(_, _), _, _), _).

% Reglas para validar si la hora ingresada esta en el horario de atencion
hora_valida(H, M) :-
    hora_inicio_servicio(HI, 0),
    hora_fin_servicio(HF, 0),
    (H >= HI, H =< HF).

hora_finalizacion_cita(H, MIN, HF, MINF) :-
    (MIN >= 55, MIN =< 60 ->
        HF is H + 2,
        MINF is MIN + 65 - 120
    ;MIN < 55 ->
        HF is H + 1,
        MINF is MIN + 65 - 60
    ).


% Agregar una cita para Estela con José el 2 de septiembre de 2024 a las 16:30 por correo
% agregar_cita(estela, jose, 2, 9, 2024, correo).

% Agregar una cita para Juan con Andrés el 3 de septiembre de 2024 a las 15:00 por correo
% agregar_cita(juan, andres, 3, 9, 2024, correo).

% Consultar todas las citas de José el 2 de septiembre de 2024
% citas_anfitrion_ese_dia(jose, 2, 9, 2024).

% Consultar todas las citas de Juan el 3 de septiembre de 2024
% citas_anfitrion_ese_dia(juan, 3, 9, 2024).
