CREATE SCHEMA turismo;

CREATE TABLE turismo.cidade (
	id_cidade int PRIMARY KEY,
	nome varchar(50) NOT NULL,
	estado char(50) NOT NULL,
	pais char(50) NOT NULL
);

CREATE TABLE turismo.evento (
	id_evento int PRIMARY KEY,
	nome varchar(50) NOT NULL,
	preco numeric(10,2) NOT NULL
);

CREATE TABLE turismo.cidade_evento (
	id_cidade_evento int PRIMARY KEY,
	data_ DATE NOT NULL,
	hora TIME NOT NULL,
	id_cidade int REFERENCES turismo.cidade(id_cidade),
	id_evento int REFERENCES turismo.evento(id_evento)
);

CREATE TABLE turismo.ponto_turistico (
	id_ponto int PRIMARY KEY,
	nome varchar(50) NOT NULL,
	endereco varchar(100) NOT NULL,
	preco numeric(10,2) NOT NULL,
	classificacao varchar(50) NOT NULL,
	descricao varchar(100) NOT NULL,
	id_cidade int REFERENCES turismo.cidade(id_cidade)
);

CREATE TABLE turismo.hotel (
	id_hotel int PRIMARY KEY,
	nome varchar(50) NOT NULL,
	endereco varchar(100) NOT NULL,
	classificacao varchar(50) NOT NULL,
	id_cidade int REFERENCES turismo.cidade(id_cidade)
);


CREATE TABLE turismo.tipo_servico (
	id_tipo int PRIMARY KEY,
	descricao varchar(50) NOT NULL,
	preco numeric(10,2) NOT NULL
);

CREATE TABLE turismo.servico_turistico (
	id_servico int PRIMARY KEY,
	nome varchar(50) NOT NULL,
	endereco varchar(100) NOT NULL,
	id_cidade int REFERENCES turismo.cidade(id_cidade),
	id_tipo int REFERENCES turismo.tipo_servico(id_tipo)
);


INSERT INTO turismo.cidade(id_cidade, nome, estado, pais) VALUES 
(1, 'Rio de Janeiro', 'Rio de Janeiro', 'Brasil'),
(2, 'Salvador', 'Bahia', 'Brasil'),
(3, 'Ouro Preto', 'Minas Gerais', 'Brasil'),
(4, 'Belém', 'Pará', 'Brasil'),
(5, 'Pirenópolis', 'Goiás', 'Brasil');

INSERT INTO turismo.evento(id_evento, nome, preco) VALUES
(11, 'Tour pelo Pão de Açúcar - Guia', 200.00),
(12, 'Show de banda desconhecida', 100.00),
(13, 'Aula de percurssão no Pelourinho', 70.00),
(14, 'Passeio de escuna na baia', 150.00),
(15, 'COP 30', 1000.00);

INSERT INTO turismo.cidade_evento(id_cidade_evento, data_, hora, id_cidade, id_evento) VALUES 
(21, '2025-10-20', '16:30:00', 1, 11),
(22, '2025-12-20', '19:00:00', 1, 12),
(23, '2025-12-29', '20:00:00', 2, 13),
(24, '2025-11-25', '15:30:00', 2, 14),
(25, '2025-11-29', '13:00:00', 4, 15);

INSERT INTO turismo.ponto_turistico(id_ponto, nome, endereco, preco, classificacao, descricao, id_cidade) VALUES
(31, 'Cristo Redentor', 'Parque Nacional da Tijuca', 120.00, 'Monumento', 'Monumento mais famoso do estado do Rio de Janeiro',
1),
(32, 'Pão de açúcar', 'Av. Pasteur, 520 - Urca, RJ', 180.00, 'Natureza', 'Complexo de morros com bondinho', 1),
(33, 'Pelourinho', 'Centro Histórico', 0.00, 'Histórico', 'Bairro histórico com arquitetura colonial colorida', 2),
(34, 'Praça Tiradentes', 'Centro', 0.00, 'Histórico', 'Principal praça da cidade com museus ao redor', 4),
(35, 'Cachoeira do Abade', 'Zona Rural', 60.00, 'Natureza', 'Reserva natural com trilhas e queda dagua', 5);

INSERT INTO turismo.hotel(id_hotel, nome, endereco, classificacao, id_cidade) VALUES
(41, 'Copacabana Palace', 'Av. Atlântica, 1702 - Copacabana, RJ', '5 estrelas', 1),
(42, 'Hotel Fasano Salvador', 'Praça Castro Alves, 5 - Centro', '5 estrelas', 2),
(43, 'Pousada do Mondego', 'Largo de Coimbra, 38 - Centro', '4 estrelas', 3),
(44, 'Radisson Hotel Maiorana Belém', 'Av. Brás de Aguiar, 300 - Nazaré', '3 estrelas', 4),
(45, 'Pousada Cavaleiro dos Pireneus', 'R. do Morro, 2 - Morro do Frota', '3 estrelas', 5);

INSERT INTO turismo.tipo_servico(id_tipo, descricao, preco) VALUES 
(61, 'Aventura', 600.00),
(62, 'Religioso', 90.00),
(63, 'Historico', 70.00),
(64, 'Trilha', 100.00);

INSERT INTO turismo.servico_turistico(id_servico, nome, endereco, id_cidade, id_tipo) VALUES
(51, 'Voo Livre (Parapente e Asa Delta)', 'R. Prefeito Mendes de Morais, 1500 - São Conrado', 1, 61),
(52, 'Guiamento a Pé pelo Pelourinho', 'Largo do Pelourinho, 10', 2, 63),
(53, 'Roteiro Histórico de Ouro Preto', 'Praça Tiradentes, 41 - Centro', 3, 62),
(54, 'Passeios Fluviais na Amazônia', 'Av. Blvd. Castilhos França, s/n - Campina', 4, 61),
(55, 'Aventura e Trilhas em Cachoeiras', 'R. do Bonfim, 20 - Centro', 5, 64);
